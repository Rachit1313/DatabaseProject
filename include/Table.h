#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <cstring>
#include <cstdarg>
#include "Column.h"

#define DEFAULT_COLUMN_DATA_TYPE "string"

class Table {
    private:
        char *m_tableName {nullptr};
        struct Column *row {nullptr};
        int m_size = 0;
    public:
        Table();
        Table(const char *tableName);
        int getTotalColumns(void);
        void addColumn(const char *columnName, const char *columnDataType = DEFAULT_COLUMN_DATA_TYPE, bool primaryKey = false);
        void addColumnData(int numberOfArguments, ...);
        std::ostream& display(std::ostream& ostr = std::cout);
        std::ostream& printTable(std::ostream& ostr = std::cout);
        ~Table();
        template <typename T>
        void deleteRow(const char *columnName, T data);
        void deleteRow(const char *columnName, std::string data);
};

template <typename T>
void Table::deleteRow(const char *columnName, T data)
{
    for (int i = 0; i < this->m_size; ++i) {
        if (strcmp(this->row[i].getColumnName(), columnName) == 0) { // Locate the column with name 'columnName'
            int index = this->row[i].checkData(data);
            if (index >= 0) {
                for (int i = 0; i < this->m_size; ++i) {
                    this->row[i].deleteData(index);
                }
            } 
        }
    }
}



#endif // _TABLE_H
