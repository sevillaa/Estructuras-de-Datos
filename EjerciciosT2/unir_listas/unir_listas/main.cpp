#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int letras[26] = {0};
        int letra;
        int i = 0, j = 0;
        int actual= 0,  maximo = 0;

        //Trabajo en asci, a la que un valor de letras valga mas de 1 se devuelve la cadena
        while(j < s.size()){
            letra = s[j] - 97;
            if(letra < 26 && letra >= 0){
                if(letras[letra] <= 0){
                    letras[letra]++;
                }
                else{
                    memset(letras, 0, sizeof(letras));
                    i++;
                    j = i;
                    letras[s[i]]++;
                    actual = 0;
                }
            }
            actual++;
            if(actual > maximo){
                if(letra != (-65) || maximo != 1)
                    maximo = actual;
            }
            j++;
        }
        return maximo;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Introduce una cadena: ";
    cin >> s;
    cout << "Longitud de la subcadena sin repetir más larga: " << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}

