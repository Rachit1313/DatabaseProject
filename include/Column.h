#ifndef _COLUMN_H
#define _COLUMN_H
#include <iostream>
#include <cstring>

#define DEFAULT_COLUMN_DATA_TYPE "string"

union Data {
    int m_intData;
    std::string m_stringData= "";
    double m_doubleData;
    char m_charData;
    Data();
    ~Data();
};

struct Column {
    private:
        char* m_columnName{nullptr};
        char* m_type{nullptr};
        union Data *m_data{nullptr};
        int m_size= 0;
        bool primaryKey = false;
    public:
        Column();
        Column(const char* name, const char *type = DEFAULT_COLUMN_DATA_TYPE, bool primaryKey = false);
        bool addData(int data);
        bool addData(double Data);
        bool addData(std::string newdata);
        bool addData(char data);
        void popData(void);
        char* getType();
        int getSize();
        bool getPrimaryKey();
        const char *getColumnName() const;
        std::ostream& display(std::ostream& ostr);
        std::ostream& displayOneColumnData(std::ostream& ostr, int index, int width = 1);
        void freeMemory();
};

#endif