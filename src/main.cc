#include <iostream>
#include <string>
#include "../include/Table.h"
#include "../include/Column.h"

int main(void)
{
    Table t("Student");

    t.addColumn("Number", "int", true);
    t.addColumn("Name", "string", true);
    t.addColumn("Marks", "double");
    t.addColumn("Grade", "char");
    t.addColumnData(t.getTotalColumns(), 2, "Jaskarn Singh", 97.55, 'F');
    t.addColumnData(t.getTotalColumns(), 6, "Rachit Chawla", 34.728, 'A');
    t.addColumnData(t.getTotalColumns(), 2, "Gurkomal", 77.69, 'G');
    t.addColumnData(t.getTotalColumns(), 184, "Test Name 1", 104.01, 'B');
    t.addColumnData(t.getTotalColumns(), 7, "Abhishek", 101.45, 'W');

    t.deleteRow("Number", 184);
    t.deleteRow("Name", std::string("Abhishek"));
    
    t.printTable();
}