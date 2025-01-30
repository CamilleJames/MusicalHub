#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "musical.h"
using namespace std;
Musical Don_Juan;
Musical Le_Rouge_et_le_Noir;
Musical Notre_Dame_de_Paris;
Musical Mozart;
Musical Moliere;
Musical La_legende_de_Roi_Arthur;
Musical Romeo_et_Juliette;
POTO Phantom_of_the_Opera;
RBC Rebecca;
Musical This;
string filename="";

Musical *Arr[9] = {&Don_Juan, &Le_Rouge_et_le_Noir, &Notre_Dame_de_Paris, &Mozart, &Moliere, &La_legende_de_Roi_Arthur, &Romeo_et_Juliette, &Phantom_of_the_Opera, &Rebecca};

void WhichMusical(){
    cout << "选择一场剧吧!" << endl;
    cout << "A.董娟\nB.法红黑\nC.nddp\nD.法扎\nE.莫里哀\nF.法亚瑟\nG.法罗朱\nH.poto\nI.蝴蝶梦\n";
    char whichmusical;
    cin >> whichmusical;
    if(whichmusical=='A'){
        This = Don_Juan;
        filename="00Don_Juan.txt";
    }else if(whichmusical=='B'){
        This = Le_Rouge_et_le_Noir;
        filename="01Le_Rouge_et_le_Noir.txt";
    }else if(whichmusical=='C'){
        This = Notre_Dame_de_Paris;
        filename="02Notre_Dame_de_Paris.txt";
    }else if(whichmusical=='D'){
        This = Mozart;
        filename="03Mozart.txt";
    }else if(whichmusical=='E'){
        This = Moliere;
        filename="04Moliere.txt";
    }else if(whichmusical=='F'){
        This = La_legende_de_Roi_Arthur;
        filename="05La_legende_de_Roi_Arthur.txt";
    }else if(whichmusical=='G'){
        This = Romeo_et_Juliette;
        filename="06Romeo_et_Juliette.txt";
    }else if(whichmusical=='H'){
        This = Phantom_of_the_Opera;
        filename = "07Phantom_of_the_Opera.txt";
    }else if(whichmusical=='I'){
        This = Rebecca;
        filename = "08Rebecca.txt";
    }else{
        cout << "o,快停止调戏这个程序! 不要随意学习酱马可" << endl;
        WhichMusical();
    }
}
void WhichBEMusical(){
    cout << "选择一场剧吧!" << endl;
    cout << "A.poto\nB.蝴蝶梦\n";
    char whichmusical;
    cin >> whichmusical;
    if(whichmusical=='A'){
        filename = "07Phantom_of_the_Opera.txt";
        Phantom_of_the_Opera.POTOChange_Ending();
    }else if(whichmusical=='B'){
        
        filename = "08Rebecca.txt";
        Rebecca.RBCChange_Ending();
    }else{
        cout << "o,快停止调戏这个程序! 不要随意学习酱马可" << endl;
        WhichBEMusical();
    }
}
template<typename T>
void Calculate(){
    T originalprice;
    T price_fornow;
    double ratio;
    srand(static_cast<unsigned int>(time(0)));
    int randomValue = rand();
    ratio = (randomValue % 100) / 100.0 + (randomValue % 3);
    cout << "鉴于市场过于火爆, 官网票已经售罄, 你只能通过黄牛获取票票! 你想要哪部剧多少价位的票? 但愿现在能够杀牛成功" << endl;
    WhichMusical();
    cin >> originalprice;

    price_fornow = ratio * originalprice;
    cout << "黄牛: "<<price_fornow << endl;
    cout << "你杀牛成功了么? 祝你看剧快乐!" << endl;
}
template<typename T>
void Inquiry(T message){
    int op = 0;
    for (int i = 0; i < 9;++i){
        
    }

        if (op == 0)
        {
            cout << "很可惜, 查无此剧. Better luck next time!" << endl;
        }
}

void Option()
{
    cout << "请选择你想进行的操作, 来建设剧韭社区并方便你的观剧之旅!" << endl;
    cout << "A.添加介绍信息,贡献者老师们最棒了!!么么" << endl;
    cout << "B.改变场次信息,四舍五入你也是沪✌" << endl;
    cout << "C.无敌加场, 上海关心你,我是说,上海真的关心你" << endl;
    cout << "D.检测你的时间是否允许观剧,加油剧韭!祝你有充足机酒钱" << endl;
    cout << "E.看看现在剧场情报怎么样了" << endl;
    cout << "F.个人二创与番外, 一些不知道好不好吃的饭" << endl;
    cout << "G.留下你的评论" << endl;
    cout << "H.如果官网票售罄, 来看看黄牛价格吧" << endl;
    cout << "I.查询窗口! 想根据别名/卡司/时间/价格选剧?" << endl;
    cout << "J.退出" << endl;
    char option;
    cin >> option;
    if(option=='J'){
        cout << "欢迎下次再来!祝你有充足的机酒钱" << endl;
        return;
    }else if (option == 'A') {
        WhichMusical();
        This.add_introduction(filename);
    }else if(option=='B'){
        WhichMusical();
        This.change_showtime(filename);
    }else if(option=='C'){
        WhichMusical();
        This.add_showtime(filename);
    }else if(option=='D'){
        WhichMusical();
        This.check_for();
    }else if(option=='E'){
        WhichMusical();
        This.show_info(filename);
    }else if(option=='F'){
        WhichBEMusical();
    }else if(option=='G'){
        WhichMusical();
        This.Leave_Remark(filename);
    }else if(option=='H'){
        Calculate<double>();
    }else if(option=='I'){
        cout << "告诉我们你想通过什么查询?" << endl;
        cout << "A.别名" << endl;
        cout << "B.卡司" << endl;
        cout << "C.时间" << endl;
        cout << "D.价格" << endl;
        char ch;
        cin >> ch;
        if(ch=='A'||ch=='B'||ch=='C'){
            string message;
            getline(cin, message);
            Inquiry(message);
        }else if(ch=='D'){
            float money;
            cin >> money;
            Inquiry(money);
        }

    }
    
    else{
        cout << "o,快停止调戏这个程序! 不要随意学习酱马可" << endl;
    }
    sleep(2);
    Option();
    
}
int main(){
    
   
    cout << "欢迎来到剧韭世界!为了拉你入坑,我们将给出一些介绍" << endl;
    Don_Juan.show_info("00Don_Juan.txt");
    sleep(10);
    Le_Rouge_et_le_Noir.show_info("01Le_Rouge_et_le_Noir.txt");
    sleep(10);
    Notre_Dame_de_Paris.show_info("02Notre_Dame_de_Paris.txt");
    sleep(10);
    Mozart.show_info("03Mozart.txt");
    sleep(10);
    Moliere.show_info("04Moliere.txt");
    sleep(10);
    La_legende_de_Roi_Arthur.show_info("05La_legende_de_Roi_Arthur.txt");
    sleep(10);
    Romeo_et_Juliette.show_info("06Romeo_et_Juliette.txt");
    sleep(10);
    Phantom_of_the_Opera.show_info("07Phantom_of_the_Opera.txt");
    sleep(10);
    Rebecca.show_info("08Rebecca.txt");
    sleep(10);

    Option();

    return 0;
}