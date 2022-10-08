#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <cstring>
#include <cstdarg>
#include "Column.h"

class Table {
    private:
        char *m_tableName {nullptr};
        struct Column *row {nullptr};
        int m_size = 0;
    public:
        Table();
        Table(const char *tableName);
        int getTotalColumns(void);
        void addColumn(const char *columnName, const char *columnDataType);
        void addColumnData(int numberOfArguments, ...);
        std::ostream& display(std::ostream& ostr = std::cout);
        ~Table();
};

#endif // _TABLE_H
