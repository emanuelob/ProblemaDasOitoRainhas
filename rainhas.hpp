#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

class Rainhas {
 public:
    Rainhas(const char* filename);
    int verifica();
 private:
    const char* filename;
};

#endif  // RAINHAS_HPP_
