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
        template <typename T>
        int updateData(int index, T data);
        int updateData(int index, std::string data);
        void deleteData(int index);
        void getData(void);
        char* getType();
        int getSize();
        bool getPrimaryKey();
        const char *getColumnName() const;
        std::ostream& display(std::ostream& ostr);
        std::ostream& displayOneColumnData(std::ostream& ostr, int index, int width = 1);
        void freeMemory();
        template <typename T>
        int checkData(T data);
        int checkData(std::string data);
};

template <typename T>
int Column::updateData(int index, T data)
{
    if (strcmp(this->m_type, "int") == 0) {
        this->m_data[index].m_intData = data;
        return 1; // Data is successfully updated
    }
    else if (strcmp(this->m_type, "double") == 0) {
        this->m_data[index].m_doubleData = data;
        return 1; // Data is successfully updated
    }
    else if (strcmp(this->m_type, "char") == 0) {
        this->m_data[index].m_charData = data;
        return 1; // Data is successfully updated
    }
    return 0; // Data not updated
}

template <typename T>
int Column::checkData(T data)
{
    for (int i = 0; i < this->m_size; ++i) {
    if (strcmp(this->m_type, "int") == 0) {
        if (this->m_data[i].m_intData == data)
            return i;
    }
    else if (strcmp(this->m_type, "double") == 0) {
        if (this->m_data[i].m_doubleData == data)
            return i;
    }
    else if (strcmp(this->m_type, "char") == 0) {
        if (this->m_data[i].m_charData == data)
            return i;
    }
    }
    return -1;
}



#endif