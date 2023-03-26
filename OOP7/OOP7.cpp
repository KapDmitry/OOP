//Kaпалин Д.С. 201
// Спроектировать простейший «графический» векторный редактор.
//Требование  функционалу редактора :
//создание нового документа
//импорт документа из файла
//экспорт документа в файл

#include "document.hpp"
#include <fstream>
using namespace std;
int main() {
    Document<int> doc;
    int s;
    ifstream in;
    ofstream out;
    cout << "1 - create new document" << "\n";
    cout << "2 - open document" << "\n";
    cout << "3 - save document" << "\n";
    cout << "4 - add a figure" << "\n";
    cout << "5 - remove a figure" << "\n";
    cout << "6 - print document" << "\n";
    cout << "7 - undo changes" << "\n";
    cout << "8 - exit" << "\n";
    cout << "Use this typenames for initializing new figures" << "\n";
    cout << "T - Trapeze" << "\n";
    cout << "R - Rhomb" << "\n";
    cout << "P - Pentagon" << "\n";
    while (cin >> s) {
        if (s == 1) {
            doc.CreateNew();
            cout << "document created!" << "\n";
        }
        else if (s == 2) {
            string u;
            cin >> u;
            in = ifstream(u);
            if (in.bad()) {
                cout << "No such file on directory" << "\n";
            }
            else {
                in >> doc;
                cout << "Loaded data from " << u << "\n";
                in.close();
            }
        }
        else if (s == 3) {
            string u;
            cin >> u;
            out = ofstream(u);
            out << doc;
            cout << "Document saved as " << u << "\n";
            out.close();

        }
        else if (s == 4) {
            size_t pos;
            char type;
            int t;
            cout << "Enter position of figure and type" << "\n";
            cin >> pos >> type;
            if (type == 'P') {
                t = 3;
            }
            if (type == 'R') {
                t = 2;
            }
            if (type == 'T') {
                t = 1;
            }
           
            ++pos;
            doc.Add(pos, t, cin);
        }
        else if (s == 5) {
            size_t pos;
            cout << "Enter position of figure" << "\n";
            cin >> pos;
            ++pos;
            doc.Delete(pos);
            cout << "Deleted\n";
        }
        else if (s == 6) {
            cout << doc;
        }
        else if (s == 7) {
            doc.Undo();
        }
        else if (s == 8) {
            exit(1);
        }
    }
    return 0;
}