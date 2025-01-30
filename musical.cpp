#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "musical.h"
using namespace std;

// get info from file
void Musical::Get_info(string filenames){
    ifstream file(filenames);
    string tmp_mp;
    getline(file, tmp_mp);
    MinPrice = stof(tmp_mp);
    getline(file, introduction);
    string tmp_ns, tmp_nc;
    getline(file, tmp_ns);
    n_s = stoi(tmp_ns);
    getline(file, tmp_nc);
    n_c = stoi(tmp_nc);
    for (int i = 1; i <= n_s;++i){
        string tmpi;
        getline(file, tmpi);
        getline(file, showtime[i]);
    }
    for (int i = 1; i <= n_c;++i){
        string tmpi;
        getline(file, tmpi);
        getline(file, cast[i]);
    }
    string tmp_nr;
    getline(file, tmp_nr);
    n_r = stoi(tmp_nr);
    remark.resize(n_r+1);
    for (int i = 1; i <= n_r;++i){
        getline(file, remark[i]);
    }
    file.close();
}

void Musical::Save_info(string filenames){
    ofstream fin(filenames);
    fin << MinPrice << endl;
    fin << introduction << endl;
    fin << n_s << endl;
    fin << n_c << endl;
    for (int i = 1; i <= n_s;++i){
        fin << i << endl;
        fin << showtime[i] << endl;
    }
    for (int i = 1; i <= n_c;++i){
        fin << i << endl;
        fin << cast[i] << endl;
    }
    fin << n_r << endl;
    
    for (int i = 1; i <= n_r;++i){
        fin << remark[i] << endl;
    }
    fin.close();
}

void Musical::add_introduction(string filename)
{
    cout << "你想把什么加入我们的档案馆呢?请输入内容" << endl;
    string addintro;
    getline(cin, addintro);
    introduction += addintro;
    Save_info(filename);
}
void Musical::Leave_Remark(string filename){
    cout << "留下你的评论吧!" << endl;
    string rmk;
    getline(cin, rmk);
    this->remark.push_back(rmk);
    this->n_r ++;
    Save_info(filename);
}
void Musical::change_showtime(string filename)
{
    Get_info(filename);
    cout << "要把哪一场的时间改成什么呢?" << endl;
    int i;
    string newtime;
    cout << "场次:";
    cin >> i;
    cout << "日期:";
    cin>> newtime;
    showtime[i] = newtime;
    Save_info(filename);
}
void Musical::add_showtime(string filename)
{
    Get_info(filename);
    cout << "哇哦,一次加场? 什么日期?" ;
    string newtime;
    cin >> newtime;
    cout << endl;
    n_s++;
    showtime[n_s] = newtime;
    Save_info(filename);
}
// show the info of the play
void Musical::show_info(string filename)
{
    Get_info(filename);
    cout << introduction << endl;
    for (int i = 1; i <= n_s; ++i)
    {
        cout << "档期" << i << ": " << showtime[i] << endl;
    }
    for (int i = 1; i <= n_c; ++i)
    {
        cout << cast[i] << endl;
    }
    cout << "恭喜你, 恭喜你! 最少只需要被收割" << MinPrice << "元就可以喜提精神的富饶与物质的贫困了!" << endl ;
    cout << "评论(" << n_r << ")" << endl;
    for (int i = 1; i <= n_r;++i){
        cout << "RMK: " << remark[i] << endl;
    }
    cout << endl;
}
void Musical::check_for()
{
    string date;
    cin >> date;
    bool yn = false;
    for (int i = 1; i <= n_s; ++i){
        if (date == showtime[i]){
            yn = true;
            cout << "可以去第" << i << "场看的开心! 祝一个成功的sd~" << endl;
        }
    }
    if (!yn){
        cout << "好可惜,所有场次都去不了是什么水平!上海关心你...I mean, literally, 沪cares about you. Bisous!" << endl;
    }
}

void POTO::POTOChange_Ending(){
    cout << "你在为魅影与克里斯汀感到意难平吗...是否想看到一个新的结局?" << endl;
    cout << "是否开启真爱不死支线?" << endl;
    cout << "A.是的,我想看到一个新的结局" << endl;
    cout << "B.不,我觉得原来的结局就很好" << endl;
    char choice;
    cin >> choice;
    if(choice=='A'){
        cout<<"进入真爱不死支线"<<endl;
        sleep(1);
        cout << "\033[2J\033[1;1H";
        cout << "并没有写完致歉" << endl;
        
    }else if(choice=='B'){
        cout << "好吧,那就继续欣赏原来的结局吧" << endl;
        return;
    }else{
        cout<<"若不保持严肃态度, 恐将喜提浮士德同款结局哦" << endl;
        this->POTOChange_Ending();
    }
}

void RBC::RBCChange_Ending(){
    cout << "或许你想看到一个并非活在他人记忆里的Rebecca吗?" << endl;
    cout << "是否开启第一视角支线?" << endl;
    cout << "A.是的,我想试图看到Rebecca的音容笑貌" << endl;
    cout << "B.不,我认为语言不足以描述她" << endl;
    char choice;
    cin >> choice;
    if(choice=='A'){
        cout<<"进入Rebecca个人向支线: 兰花与野火与灰烬"<<endl;
        sleep(1);
        cout << "\033[2J\033[1;1H";
        cout << "时至今日我对吕蓓卡的面庞她五官的具体细节早已模糊不清, 但她那双透亮的燃烧着野火般的眼珠仍然固执地扎根在我记忆里, 那双琥珀色眼珠被光线打的通通透透" << endl;
        sleep(1);
        cout << "虹膜的纹路纤毫毕现, 燎原的火焰熊熊燃烧, 类似灼烫又短暂的东西, 即便我不知道自己为什么会这样觉得. 我想起那些说起她应该投个男胎的议论" << endl;
        sleep(1);
        cout << "我是害怕承受她的目光的, 但又不可避免地期待着被她的野火灼烧的无处遁形的窘迫感, 舒适区的温水被投入红热的铁丝嘶嘶作响" << endl;
        sleep(1);
        cout << "我想了好久觉得野火是最适合她的, 吕蓓卡给我的感受正是野火, 炽烈恣肆的" << endl;
        sleep(1);
        cout << "她在使尽全身力气纵情生活么, 就像她最爱的热烈饱满的蓝紫色乳白色兰花,我知道他们说兰花高贵典雅, 但兰花孕育自大陆另一端炎热湿润的热带气候不是么" << endl;
        sleep(1);
        cout << "并没有写完致歉" << endl;
    }else if(choice=='B'){
        cout << "好吧,那就让Rebecca活在回忆与他人言语中永远光洁生鲜吧" << endl;
        return;
    }else{
        cout<<"若不保持严肃态度, 恐将喜提浮士德同款结局哦" << endl;
        this->RBCChange_Ending();
    }
    
}

void Musical::TODO()
{

}