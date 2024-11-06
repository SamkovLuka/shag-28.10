#include <iostream>
using namespace std;


setlocale(LC_ALL, "uk_UA.UTF-8");


//////домашнє завдання 1



// завдання 1
void addColumn(int**& matrix, int& rows, int& cols, int position) {
    if (position < 0 || position > cols) {
        cout << "Неправильна позиція!" << endl;
        return;
    }

    


    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols + 1];
        for (int j = 0; j < position; ++j) {
            newRow[j] = matrix[i][j];
        }
        newRow[position] = 0;
        for (int j = position; j < cols; ++j) {
            newRow[j + 1] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    ++cols;
}





// завдання 2
void removeColumn(int**& matrix, int& rows, int& cols, int position) {
    if (position < 0 || position >= cols) {
        cout << "Неправильна позиція!" << endl;
        return;
    }

   


    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols - 1];
        for (int j = 0; j < position; ++j) {
            newRow[j] = matrix[i][j];
        }
        for (int j = position + 1; j < cols; ++j) {
            newRow[j - 1] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    --cols;
}







// завдання 3
void cyclicShift(int**& matrix, int rows, int cols, bool shiftRows, int steps) {
    steps %= (shiftRows ? rows : cols);
    if (steps == 0) return;

    if (shiftRows) {
        for (int s = 0; s < steps; ++s) {
            int* temp = matrix[rows - 1];
            for (int i = rows - 1; i > 0; --i) {
                matrix[i] = matrix[i - 1];
            }
            matrix[0] = temp;
        }
    }
    else {
        for (int s = 0; s < steps; ++s) {
            for (int i = 0; i < rows; ++i) {
                int temp = matrix[i][cols - 1];
                for (int j = cols - 1; j > 0; --j) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = temp;
            }
        }
    }
}










// завдання 1
void transpose(int**& matrix, int& rows, int& cols) {
    int** newMatrix = new int* [cols];
    for (int i = 0; i < cols; ++i) {
        newMatrix[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            newMatrix[i][j] = matrix[j][i];
        }
    }
    




    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = newMatrix;

    
    swap(rows, cols);
}




// завдання 2
struct Contact {
    char name[50];
    char phone[20];
};






void addContact(Contact*& contacts, int& size, const char* name, const char* phone) {
    Contact* newContacts = new Contact[size + 1];
    for (int i = 0; i < size; ++i) {
        newContacts[i] = contacts[i];
    }
    strncpy(newContacts[size].name, name, 50);
    strncpy(newContacts[size].phone, phone, 20);
    delete[] contacts;
    contacts = newContacts;
    ++size;
}







void searchContact(Contact* contacts, int size, const char* query) {
    for (int i = 0; i < size; ++i) {
        if (strncmp(contacts[i].name, query, 50) == 0 || strncmp(contacts[i].phone, query, 20) == 0) {
            cout << "Знайдено контакт: " << contacts[i].name << " - " << contacts[i].phone << endl;
            return;
        }
    }
    cout << "Контакт не знайдено!" << endl;
}






void updateContact(Contact* contacts, int size, const char* name, const char* newPhone) {
    for (int i = 0; i < size; ++i) {
        if (strncmp(contacts[i].name, name, 50) == 0) {
            strncpy(contacts[i].phone, newPhone, 20);
            cout << "Номер оновлено для " << name << endl;
            return;
        }
    }
    cout << "Контакт з таким ім'ям не знайдено!" << endl;
}








int main() {
    int rows = 3, cols = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    





    addColumn(matrix, rows, cols, 1);
    cout << "Матриця після додавання стовпця:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

  





    removeColumn(matrix, rows, cols, 2);
    cout << "Матриця після видалення стовпця:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }





    cyclicShift(matrix, rows, cols, true, 1);
    cout << "Матриця після циклічного зсуву рядків:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    




    transpose(matrix, rows, cols);
    cout << "Матриця після транспонування:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    




    int contactSize = 0;
    Contact* contacts = nullptr;
    addContact(contacts, contactSize, "Олег", "123456789");
    addContact(contacts, contactSize, "Анна", "987654321");
    searchContact(contacts, contactSize, "Олег");
    updateContact(contacts, contactSize, "Олег", "111222333");

    



    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] contacts;


