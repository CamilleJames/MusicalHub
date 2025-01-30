#ifndef MUSICAL_H
#define MUSICAL_H
#include <vector>
#include <string>
using namespace std;


class Musical{
private:
    float MinPrice;
    string introduction;
    string showtime[20];
    int n_s;
    string cast[10];
    int n_c;
    vector<string> remark;
    int n_r;

public:
    Musical() {};
    virtual ~Musical() {};
    virtual void POTOChange_Ending() {};
    virtual void RBCChange_Ending() {};
    void Leave_Remark(string filename);
    void Get_info(string filename);
    void Save_info(string filename);
    void add_introduction(string filename);
    void change_showtime(string filename);
    void add_showtime(string filename);
    void show_info(string filename);
    void check_for();
    void TODO();
};

class POTO:public Musical{

public :
    void POTOChange_Ending() override;
};

class RBC:public Musical{

public:
    void RBCChange_Ending() override;
};
#endif