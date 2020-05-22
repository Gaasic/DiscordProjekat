#ifndef KOZUH_HPP_INCLUDED
#define KOZUH_HPP_INCLUDED

class NizTokena {
public:
    NizTokena(string, char);
    int brojTokena;
    string* tokeni;
};
NizTokena::NizTokena(string l, char delim) {
    brojTokena = 1;
    for (int i = 0; i < l.size(); i++) {
       if(l[i] == delim)
            brojTokena++;
    }
    tokeni = new string[brojTokena];
    int tekuciToken = 0;
    for (int i = 0; i < l.size(); i++) {
        if(l[i] == delim) {
            tekuciToken++;
            tokeni[tekuciToken] = "";
        }
        else
            tokeni[tekuciToken] += l[i];
    }
}

#endif // KOZUH_HPP_INCLUDED