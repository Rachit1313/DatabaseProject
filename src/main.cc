#include <iostream>
#include <string>
#include "../include/Table.h"
#include "../include/Column.h"

int main(void)
{
    Table t("Student");

    t.addColumn("Number", "int");
    t.addColumn("Name", "string");
    t.addColumn("Marks", "double");
    t.addColumn("Grade", "char");
    t.addColumnData(t.getTotalColumns(), 2, "Jaskarn Singh", 97.55, 'F');
    t.addColumnData(t.getTotalColumns(), 6, "Rachit Chawla", 34.728, 'A');
    t.addColumnData(t.getTotalColumns(), 184, "Test Name", 104.01, 'B');
    
    t.display();
}