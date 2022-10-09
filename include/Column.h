#ifndef _COLUMN_H
#define _COLUMN_H
#include <iostream>
#include <cstring>

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
    public:
        Column();
        Column(const char* name);
        Column(const char* name, const char *type);
        void addData(int data);
        void addData(double Data);
        void addData(std::string newdata);
        void addData(char data);
        char* getType();
        int getSize();
        const char *getColumnName() const;
        std::ostream& display(std::ostream& ostr);
        std::ostream& displayOneColumnData(std::ostream& ostr, int index, int width = 1);
        void freeMemory();
};

#endif