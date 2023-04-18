/**
 * @author [Rachit1313](https://github.com/Rachit1313)
 * @author [Jaskarn7](https://github.com/Jaskarn7)
*/

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
        template <typename PKData, typename T>
        int updateRowData(const char *primaryKeyColumnName, PKData primaryKeyValue, const char *columnName, T data);
        std::ostream& display(std::ostream& ostr = std::cout);
        std::ostream& printTable(std::ostream& ostr = std::cout);
        ~Table();
        template <typename T>
        void deleteRow(const char *columnName, T data);
        void deleteRow(const char *columnName, std::string data);
};

template <typename PKData, typename T>
int Table::updateRowData(const char *primaryKeyColumnName, PKData primaryKeyValue, const char *columnName, T data)
{
    for (int i = 0; i < this->m_size; ++i) {
        if (strcmp(this->row[i].getColumnName(), primaryKeyColumnName) == 0) {
            int index = this->row[i].checkData(primaryKeyValue);
            if (index >= 0) {
                for (int j = 0; j < this->m_size; ++j) {
                    if (strcmp(this->row[j].getColumnName(), columnName) == 0) {
                        return this->row[j].updateData(index, data);
                    }
                }
            }
        }
    }
    return 0;
}

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
