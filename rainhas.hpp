#ifndef rainhas_hpp
#define rainhas_hpp

class Rainhas {
public:
    Rainhas(const char* filename);
    int verifica();

private:
    const char* filename; 
};

#endif