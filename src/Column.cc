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
Column::Column(const char* name)
{
    if(name != nullptr){
        this->m_columnName = new char[strlen(name)+1];
        strcpy(this->m_columnName, name);
    }
}
Column::Column(const char* name, const char *type)
{
    if(name != nullptr){
        this->m_columnName = new char[strlen(name)+1];
        strcpy(this->m_columnName, name);
    }
   if(type != nullptr){
        this->m_type = new char[strlen(type)+1];
        strcpy(this->m_type, type);
    }
}
void Column::addData(int data){
    union Data tmpData;
    tmpData.m_intData = data;
    union Data *tmp = new union Data[this->m_size + 1];
    
    for(int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0)
            tmp[i].m_stringData = this->m_data[i].m_stringData;
    }
    tmp[this->m_size].m_intData = data;
    this->m_size += 1;
    
    delete[] this->m_data;
    this->m_data = tmp;
}
void Column::addData(double Data){
    union Data tmpData;
    tmpData.m_doubleData = Data;
    
    union Data *tmp = new union Data[this->m_size +1];
    for (int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0)
            tmp[i].m_stringData = this->m_data[i].m_stringData;
    }
    tmp[this->m_size].m_doubleData = Data;
    this->m_size +=1;
    
    delete[] this->m_data;
    this->m_data = tmp;
}
void Column::addData(std::string newdata)
{
    union Data *tmp = new union Data[this->m_size + 1];
    
    for (int i = 0; i < m_size; ++i) {
        if (strcmp(this->m_type, "int") == 0)
            tmp[i].m_intData = this->m_data[i].m_intData;
        else if (strcmp(this->m_type, "double") == 0)
            tmp[i].m_doubleData = this->m_data[i].m_doubleData;
        else if (strcmp(this->m_type, "string") == 0) {
            tmp[i].m_stringData = this->m_data[i].m_stringData;
        }
    }
    tmp[this->m_size].m_stringData = newdata;
    this->m_size += 1;
    
    if (this->m_data != nullptr)
        delete[] this->m_data;
    this->m_data = tmp;
}
char* Column::getType()
{
    return this->m_type;
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
    }
    std::cout << std::endl;
    std::cout.unsetf(std::ios::left);

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