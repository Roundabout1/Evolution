#ifndef GEN_H
#define GEN_H
class Gen{
private:
    int type;
public:
    Gen();
    Gen(int value);

    void set(Gen gen);
    std::string toString();
    bool equal(Gen gen);
    int getType();
};
#endif