#include <iostream>
#include "../include/Table.h"

Table::Table(){
    this->m_tableName = nullptr;
    this->row = nullptr;
    this->m_size = 0;
}
Table::Table(const char *tableName)
{
    if (tableName != nullptr) {
        this->m_tableName = new char[strlen(tableName) + 1];
        strcpy(this->m_tableName, tableName);
    }
    else {
        std::cerr << "ERROR: Table name Invalid" << std::endl;
    }
}

int Table::getTotalColumns(void)
{
    return this->m_size;
}

void Table::addColumn(const char *columnName, const char *columnDataType)
{
    struct Column tmpColumn(columnName, columnDataType);
    
    struct Column *tmp = new struct Column[m_size + 1];
    for (int i = 0; i < m_size; ++i)
        *(tmp + i) = *(this->row + i);
    *(tmp + m_size) = tmpColumn;
    this->m_size += 1;
    if(this->row != nullptr)
        delete[] this->row;
    this->row = tmp;
}
void Table::addColumnData(int numberOfArguments, ...) 
{
    va_list valist;
    va_start(valist, numberOfArguments);
    for(int i=0;i<numberOfArguments;i++){
        if (strcmp(this->row[i].getType(), "int") == 0) {
            this->row[i].addData(va_arg(valist, int));
        }
        else if (strcmp(this->row[i].getType(), "double") == 0) {
            this->row[i].addData(va_arg(valist, double));
        }
        else if (strcmp(this->row[i].getType(), "string") == 0) {
           this->row[i].addData(va_arg(valist, const char *));
        }
        else if (strcmp(this->row[i].getType(), "char") == 0) {
            this->row[i].addData((char) va_arg(valist, int));
        }
    }
    va_end(valist);
}
std::ostream& Table::display(std::ostream& ostr)
{
    ostr << std::endl;
    ostr << "|";
    ostr.width(strlen(this->m_tableName));
    ostr.fill('-');
    ostr << "" << "|" << std::endl;
    ostr << " " << this->m_tableName << std::endl;
    ostr << "|";
    ostr.width(strlen(this->m_tableName));
    ostr << "" << "|" << std::endl;
    ostr.fill(' ');
    for (int i = 0; i < this->m_size; ++i) {
        this->row[i].display(ostr);
    }
    ostr << std::endl;
    return ostr;
}

std::ostream& Table::printTable(std::ostream& ostr)
{
    ostr << std::endl;
    ostr.width(this->m_size * 27 + 1);
    ostr.fill('-');
    ostr << "" << std::endl;
    ostr.fill(' ');

    int i = 0;
    ostr.setf(std::ios::left);
    for (int i = 0; i < this->m_size; ++i) {
        ostr << "| ";
        ostr.width(25);
        ostr << this->row[i].getColumnName();
    }
    ostr.unsetf(std::ios::left);
    ostr << "|" << std::endl;
    
    ostr.width(this->m_size * 27 + 1);
    ostr.fill('-');
    ostr << "" << std::endl;
    ostr.fill(' ');
    
    while (i < this->row[0].getSize()) {
        for (int j = 0; j < this->m_size; ++j) {
            ostr << "| ";
            this->row[j].displayOneColumnData(ostr, i, 25);
        }
        std::cout << "|" << std::endl;
        ++i;
    }
    
    ostr.width(this->m_size * 27 + 1);
    ostr.fill('-');
    ostr << "" << std::endl;
    ostr.fill(' ');

}

Table::~Table()
{
    delete[] this->m_tableName;
    for (int i = 0; i < this->m_size; ++i)
        this->row[i].freeMemory();
    delete[] this->row;
}