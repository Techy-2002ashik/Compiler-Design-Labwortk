#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

vector<string> keywords ={
"int", "float", "double", "char", "string",
"if", "else", "for", "while", "return", "void", "class", "public", "private", "protected", "include", "using",
"namespace", "main", "switch", "case", "break", "continue"
};

bool myIsDigit( char c){
return c >= '0' && c <= '9';
}

bool myIsAlpha(char c){
return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z' );
}

bool myIsAlnum(char c){
return myIsAlpha(c) || myIsDigit(c);
}

bool myIsKeyword(const string & token){
for (const string & kw : keywords){
    if(kw == token) return true;
}
return false;
}

bool myIsNumber(const string & token){
if(token.empty()) return false;

for (char c : token){
    if(!myIsDigit(c)) return false;
}
return true;
}

bool myIsIdentifier(const string & token){
if(token.empty()) return false;

if(!(myIsAlpha(token[0]) || token[0] == '_')) return false;

for(char c: token){
    if(!(myIsAlnum(c) || c == '_')) return false;
}
return true;
}

bool myIsSymbol(const string & token){
string symbols = ";(){}[]=+-*/<>,.";
if(token.size()!=1) return false;

for( char s: symbols){
    if(token[0] == s)return true;
}
return false;
}

vector<string> tokenize(const string & line){
vector<string> tokens;
string current = "";

 for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];

        // If symbol → flush current and add symbol
        string symbols = ";{}()[]=+-*/<>,.";
        bool isSym = false;
        for (char s : symbols) {
            if (c == s) { isSym = true; break; }
        }

        if (isSym) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            tokens.push_back(string(1, c));
        }
        else if (c == ' ' || c == '\t') {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        }
        else {
            current += c;
        }
    }

    if (!current.empty()) tokens.push_back(current);
    return tokens;

}
int main(){
ifstream file("input.txt");

if(!file){
    cout<<" Error: Please enter the valid name of file on source code!"<< endl;
    return 1;
}

string line;

cout<<"++++File Content++++\n";
while (getline(file, line)){
cout<< line<< endl;
}
file.clear();
file.seekg(0, ios ::beg);

cout<<"\n++Tokens & it's classifications++\n";

while (getline(file, line)){
    vector<string> tokens = tokenize(line);
    for(const string & token : tokens){
        if(myIsKeyword(token)){
            cout<< token <<"--->>Keyword\n";
        }
        else if(myIsNumber(token)){
            cout<< token <<"--->>Number\n";
        }
        else if(myIsIdentifier(token)){
            cout<< token <<"--->>Identifier\n";
        }
        else if(myIsSymbol(token)){
            cout<< token <<"--->>Symbols\n";
        }
        else{
            cout<< token <<"--->>Unknown\n";
        }
    }
}

file.close();
return 0;
}
