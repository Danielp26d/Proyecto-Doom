#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const int ID = 1;  // ✅ ID fijo para todas las tuplas
    ifstream infile("entrada.txt");
    ofstream outfile("salida.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error abriendo archivos." << endl;
        return 1;
    }

    string line;
    int count = 0;  // contador de líneas procesadas

    while (getline(infile, line)) {
        stringstream ss(line);
        vector<string> parts;
        string value;

        // Leer datos separados por espacios o tabs
        while (ss >> value) {
            parts.push_back(value);
        }

        if (parts.size() < 3) continue;

        // ❌ Eliminar el último dato
        parts.pop_back();

        // ✅ Unir fecha y hora (primeros dos elementos)
        string fechaHora = parts[0] + " " + parts[1];

        // ✅ Escribir la tupla con el formato solicitado
        outfile << "(" << ID << ", '" << fechaHora << "'";
        for (size_t i = 2; i < parts.size(); i++) {
            outfile << ", " << parts[i];
        }
        outfile << "),\n";

        count++;  // incrementar el contador
    }

    infile.close();
    outfile.close();

    cout << "✅ Conversión completada." << endl;
    cout << "📊 Total de líneas procesadas: " << count << endl;

    return 0;
}
