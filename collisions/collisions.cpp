#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

/* хэширование ASCII */
unsigned int get_ascii_hash(char *S) {
    unsigned int hash = 0; 
    while(*S) {
        hash += (unsigned int)*S;
        S++;
    }
    return hash;
}

/* полиноминальный подход */
unsigned int get_poly_hash(char *S) {
    unsigned int hash = 0;
    unsigned int i = 0;
    while(*S) {
        hash += (unsigned int)pow(*S, (++i));
        S++;
    }
    return hash;
}

bool has_duplicate(vector<unsigned int> v, unsigned int value) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == value)
            return true;
    }
}

int main(void) {
    char buff[64];
    ifstream fin("endict.txt");
    vector<unsigned int> ascii_collisions;
    vector<unsigned int> poly_collisions;
    unsigned int number_of_ascii_collisions = 0;
    unsigned int number_of_poly_collisions = 0;
    unsigned int ascii_hash = 0;
    unsigned int poly_hash = 0;

    do {
        fin.getline(buff, 50);
        /* ASCII коллизии */
        ascii_hash = get_ascii_hash(buff);
        if (has_duplicate(ascii_collisions, ascii_hash))
            number_of_ascii_collisions++;
        else
            ascii_collisions.push_back(ascii_hash);

    } while (!fin.eof());
    cout << "Number of ASCII method is: " << number_of_ascii_collisions << endl;
}