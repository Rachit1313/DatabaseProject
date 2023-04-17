/**
 * @author [Rachit1313](https://github.com/Rachit1313)
 * @author [Jaskarn7](https://github.com/Jaskarn7)
*/

#include <iostream>
#include "../include/Column.h"

Data::Data() {};
Data::~Data() {};

Column::Column(){
    this->m_columnName = nullptr;
    this->m_type = nullptr;
    this->m_data = nullptr;
    this->m_size = 0;
}

Column::Column(const char* name, const char *type, bool primaryKey)
{
    if(name != nullptr){
        this->m_columnName = new char[strlen(name)+1];
        strcpy(this->m_columnName, name);
    }
    if(type != nullptr){
        this->m_type = new char[strlen(type)+1];
        strcpy(this->m_type, type);
    }
    if (primaryKey) {
        this->primaryKey = true;
    }
}
bool Column::addData(int data){
    union Data tmpData;
    tmpData.m_intData = data;
    union Data *tmp = new union Data[this->m_size + 1];

    for (int i = 0; this->getPrimaryKey() && i < this->m_size; ++i) {
        if (this->m_data[i].m_intData == data)
            return false;
    }
    
    for(int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0)
            tmp[i].m_stringData = this->m_data[i].m_stringData;
        else if (strcmp(this->m_type, "char") == 0) {
            tmp[i].m_charData = this->m_data[i].m_charData;
        }
    }
    tmp[this->m_size].m_intData = data;
    this->m_size += 1;
    
    delete[] this->m_data;
    this->m_data = tmp;

    return true; // Data added successfully
}
bool Column::addData(double Data){
    union Data tmpData;
    tmpData.m_doubleData = Data;

    for (int i = 0; this->getPrimaryKey() && i < this->m_size; ++i) {
        if (this->m_data[i].m_doubleData == Data)
            return false;
    }
    
    union Data *tmp = new union Data[this->m_size +1];
    for (int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0)
            tmp[i].m_stringData = this->m_data[i].m_stringData;
        else if (strcmp(this->m_type, "char") == 0)
            tmp[i].m_charData = this->m_data[i].m_charData;
    }
    tmp[this->m_size].m_doubleData = Data;
    this->m_size +=1;
    
    delete[] this->m_data;
    this->m_data = tmp;

    return true; // Data added successfully
}
bool Column::addData(std::string newdata)
{
    union Data *tmp = new union Data[this->m_size + 1];
    
    for (int i = 0; this->getPrimaryKey() && i < this->m_size; ++i) {
        if (this->m_data[i].m_stringData == newdata)
            return false;
    }
    
    for (int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0) {
            tmp[i].m_stringData = this->m_data[i].m_stringData;
        }
        else if (strcmp(this->m_type, "char") == 0) {
            tmp[i].m_charData = this->m_data[i].m_charData;
        }
    }
    tmp[this->m_size].m_stringData = newdata;
    this->m_size += 1;
    
    if (this->m_data != nullptr)
        delete[] this->m_data;
    this->m_data = tmp;

    return true; // Data added successfully
}
bool Column::addData(char data)
{
    union Data *tmp = new union Data[this->m_size + 1];
    
    for (int i = 0; this->getPrimaryKey() && i < this->m_size; ++i) {
        if (this->m_data[i].m_charData == data)
            return false;
    }
    
    for (int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0) {
            tmp[i].m_stringData = this->m_data[i].m_stringData;
        }
        else if (strcmp(this->m_type, "char") == 0) {
            tmp[i].m_charData = this->m_data[i].m_charData;
        }
    }
    tmp[this->m_size].m_charData = data;
    this->m_size += 1;
    
    if (this->m_data != nullptr)
        delete[] this->m_data;
    this->m_data = tmp;

    return true; // Data added successfully
}

void Column::popData()
{
    this->m_size -= 1;

    union Data *tmp = new union Data[this->m_size];
    
    for (int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0) {
            tmp[i].m_stringData = this->m_data[i].m_stringData;
        }
        else if (strcmp(this->m_type, "char") == 0) {
            tmp[i].m_charData = this->m_data[i].m_charData;
        }
    }
    
    if (this->m_data != nullptr)
        delete[] this->m_data;
    this->m_data = tmp;
}

int Column::updateData(int index, std::string data)
{
    this->m_data[index].m_stringData = data;
    return 1;
}


void Column::deleteData(int index)
{
    union Data *tmp = new union Data[this->m_size - 1];

    int i = 0; // Loop for this->m_data
    int j = 0; // Loop for tmp
    for (int i = 0; i < m_size; ++i) {
        if (i == index)
            continue; // Skip
        if (strcmp(this->m_type, "int") == 0)
            tmp[j++].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[j++].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0) {
            tmp[j++].m_stringData = this->m_data[i].m_stringData;
        }
        else if (strcmp(this->m_type, "char") == 0) {
            tmp[j++].m_charData = this->m_data[i].m_charData;
        }
    }

    this->m_size -= 1;
    
    if (this->m_data != nullptr)
        delete[] this->m_data;
    this->m_data = tmp;
}

char* Column::getType()
{
    return this->m_type;
}
int Column::getSize()
{
    return this->m_size;
}

bool Column::getPrimaryKey()
{
    return this->primaryKey;
}


const char *Column::getColumnName() const
{
    return (const char *) this->m_columnName;
}


std::ostream& Column::display(std::ostream& ostr)
{
    std::cout.setf(std::ios::left);
    std::cout.width(10);
    std::cout << this->m_columnName << " (";
    std::cout.width(6);
    std::cout << this->m_type << ")" ;
    for (int i = 0; i < this->m_size; ++i) {
        std::cout << " | ";
        std::cout.width(25);
        if (strcmp(this->m_type, "int") == 0)
            std::cout << this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            std::cout << this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0)
            std::cout << this->m_data[i].m_stringData;
        else if (strcmp(this->m_type, "char") == 0)
            std::cout << this->m_data[i].m_charData;
    }
    std::cout << std::endl;
    std::cout.unsetf(std::ios::left);

    return ostr;
}
std::ostream& Column::displayOneColumnData(std::ostream& ostr, int index, int width)
{
    ostr.width(width);
    ostr.setf(std::ios::left);
    if (strcmp(this->m_type, "int") == 0)
            ostr << this->m_data[index].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            ostr << this->m_data[index].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0)
            ostr << this->m_data[index].m_stringData;
        else if (strcmp(this->m_type, "char") == 0)
            ostr << this->m_data[index].m_charData;
    ostr.unsetf(std::ios::left);
    return ostr;
}

void Column::freeMemory()
{
    if (this->m_columnName != nullptr)
        delete[] this->m_columnName;
    if (this->m_type != nullptr)
        delete[] this->m_type;
    if (this->m_data != nullptr)
        delete[] this->m_data;
}

int Column::checkData(std::string data)
{
    for (int i = 0; i < this->m_size; ++i) {
        if (this->m_data[i].m_stringData == data)
            return i;
    }
    return -1;
}  

