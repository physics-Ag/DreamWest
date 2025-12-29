#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

void makephototransparent(int x, int y, IMAGE a, IMAGE b);
void Battle();
void menu();

//背景类
class gamebackground {
public:
    gamebackground(const char* a)
    {
        x = 0;
        y = 0;

        loadimage(&cover, a, 960, 540);
        loadimage(&background, a, 960, 540);
    }

    void paint()
    {
        putimage(x, y, &background);
        putimage(x, y, &cover);
    }
private:
    IMAGE background, cover;
    int x, y;
};

class role {
public:
    //构造函数对类中初始化
    role()
    {
        PBlood_Volume = 100;

        PPsychic_Power = 100;

        Blood_Volume = 100;

        Psychic_Power = 100;

        Gold = 100;

        Variable = 0;

        x = 450;
        y = 350;

        //加载向左走的图片
        char lpathB[30] = ".\\role\\left\\Bleft%d.png";
        char lpath[30] = ".\\role\\left\\left%d.png";
        for (int i = 1; i < 5; i++)
        {
            char path1[30], path2[30];
            sprintf(path1, lpathB, i);
            sprintf(path2, lpath, i);
            loadimage(&leftp1[i - 1], _T(path1));
            loadimage(&leftp2[i - 1], _T(path2));
        }

        //加载向右走的图片
        char rpathB[30] = ".\\role\\right\\Bright%d.png";
        char rpath[30] = ".\\role\\right\\right%d.png";
        for (int i = 1; i < 5; i++)
        {
            char path1[30], path2[30];
            sprintf(path1, rpathB, i);
            sprintf(path2, rpath, i);
            loadimage(&rightp1[i - 1], path1);
            loadimage(&rightp2[i - 1], path2);
        }

        //加载法术1释放的图片
        for (int i = 1; i < 14; i++)
        {
            char path1[30], path2[30];
            sprintf(path1, ".\\role\\Magic_Arts1\\B%d.png", i);
            sprintf(path2, ".\\role\\Magic_Arts1\\%d.png", i);
            loadimage(&BMagic_Arts1[i - 1], path1);
            loadimage(&Magic_Arts1[i - 1], path2);
        }

        //加载法术2释放的图片
        for (int i = 1; i < 14; i++)
        {
            char path1[30], path2[30];
            sprintf(path1, ".\\role\\Magic_Arts2\\B%d.png", i);
            sprintf(path2, ".\\role\\Magic_Arts2\\%d.png", i);
            loadimage(&BMagic_Arts2[i - 1], path1);
            loadimage(&Magic_Arts2[i - 1], path2);
        }

        //占位图
        loadimage(&cover, ".\\role\\ground\\ground.png");
        loadimage(&background, ".\\homepage\\background.png");

        //加载角色站立图
        loadimage(&Bstand, ".\\role\\stand\\Bstand.png");
        loadimage(&stand, ".\\role\\stand\\stand.png");

        //加载角色战斗站立图
        loadimage(&battle_stand, ".\\role\\battle_stand\\battle_stand.png");
        loadimage(&Bbattle_stand, ".\\role\\battle_stand\\Bbattle_stand.png");

        x1 = 100;
        y1 = 200;

        state1 = -1;
        state2 = -1;

        xs1 = 0;
        ys1 = 0;

        xs2 = 0;
        ys2 = 0;
    }

    void move()
    {
        bool isA = false;
        bool isD = false;

        int i = 0, j = 0;
        cleardevice();
        putimage(0, 0, &background);
        makephototransparent(x, y, Bstand, stand);
        while (1)
        {
            // 检查 A 键是否被按下
            if (GetAsyncKeyState('A') & 0x8000)
            {
                if (!isA)
                {
                    mciSendString("open .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                    mciSendString("play .\\music\\FootSound.mp3", nullptr, 0, nullptr);

                    isA = true;
                }

                // 执行向左移动的动画
                BeginBatchDraw();
                cleardevice();
                putimage(0, 0, &background);
                makephototransparent(x, y, leftp1[i], leftp2[i]);
                Sleep(100);

                if (x < 200)
                {
                    x = 450;
                    y = 350;
                    mciSendString("stop .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                    mciSendString("close .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                    Battle();
                }

                if (x < 450 && x > 280)
                {
                    x -= 5;
                    y -= 1;
                }
                else if (x < 280)
                {
                    x -= 2;
                    y -= 2;
                }
                else if (x > 450 && x < 600)
                {
                    x -= 5;
                    y += 1;
                }
                else
                {
                    x -= 2;
                    y += 2;
                }
                if (i == 3)
                {
                    i = 0;
                }
                else
                {
                    i++;
                }
                EndBatchDraw();
            }
            else if (GetAsyncKeyState('D') & 0x8000)
            {
                if (!isD)
                {
                    mciSendString("open .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                    mciSendString("play .\\music\\FootSound.mp3", nullptr, 0, nullptr);

                    isD = true;
                }

                // 执行向右移动的动画
                BeginBatchDraw();
                cleardevice();
                putimage(0, 0, &background);
                makephototransparent(x, y, rightp1[j], rightp2[j]);
                Sleep(100);

                if (x > 680)
                {
                    x = 450;
                    y = 350;
                    mciSendString("stop .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                    mciSendString("close .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                    Battle();
                }

                if (x > 450 && x < 600)
                {
                    x += 5;
                    y -= 1;
                }
                else if (x > 600)
                {
                    x += 2;
                    y -= 2;
                }
                else if (x < 450 && x > 280)
                {
                    x += 5;
                    y += 1;
                }
                else
                {
                    x += 2;
                    y += 2;
                }
                if (j == 3)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
                EndBatchDraw();
            }
            else
            {
                mciSendString("stop .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                mciSendString("close .\\music\\FootSound.mp3", nullptr, 0, nullptr);
                isD = false;
                isA = false;
            }
        }
    }

    void increase()
    {
        PBlood_Volume += 100;
        PPsychic_Power += 100;
    }

    int putBlood_Volume()
    {
        return Blood_Volume;
    }

    void fresh()
    {
        Blood_Volume = PBlood_Volume;
        Psychic_Power = PPsychic_Power;
        state1 = -1;
        state2 = -1;
        Variable = 0;
    }

    void fresh_start()
    {
        Blood_Volume = 100;
        Psychic_Power = 100;
        state1 = -1;
        state2 = -1;
        Variable = 0;
    }

    int putPsychic_Power()
    {
        return Psychic_Power;
    }

    int putstate1()
    {
        return state1;
    }

    int putstate2()
    {
        return state2;
    }

    int putV()
    {
        return Variable;
    }

    void reduce1()
    {
        Blood_Volume -= 5;
    }

    void reduce2()
    {
        Blood_Volume -= 5;
    }

    void reduce3()
    {
        Blood_Volume -= 10;
    }

    void paint()
    {
        settextstyle(20, 0, "微软雅黑");
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        char arr1[30];
        sprintf(arr1, "灵力：%d", Psychic_Power);
        outtextxy(100, 140, arr1);

        char arr2[30];
        sprintf(arr2, "血量：%d", Blood_Volume);
        outtextxy(100, 170, arr2);

        makephototransparent(x1, y1, Bbattle_stand, battle_stand);

        if (state1 != -1)
        {
            for (int i = 0; i < 13; i++)
            {
                makephototransparent(xs1, ys1, BMagic_Arts1[state1], Magic_Arts1[state1]);
            }
            makephototransparent(xs1, ys1, BMagic_Arts1[state1], Magic_Arts1[state1]);
            if (state1 == 12)
            {
                state1 = -1;
            }
            else
            {
                state1++;
            }
        }

        if (state2 != -1)
        {
            makephototransparent(xs2, ys2, BMagic_Arts2[state2], Magic_Arts2[state2]);
            if (state2 == 12)
            {
                state2 = -1;
            }
            else
            {
                state2++;
            }
        }
    }

    void update1(int px, int py)
    {
        xs1 = px;
        ys1 = py;
        state1++;
    }

    void update2(int px, int py)
    {
        xs2 = px;
        ys2 = py;
        state2++;
    }

    bool Psychic_Power_update1()
    {
        if (Psychic_Power - 10 < 0)
        {
            return false;
        }
        else
        {
            Psychic_Power -= 10;
            Variable++;
            return true;
        }
    }

    bool Psychic_Power_update2()
    {
        if (Psychic_Power - 15 < 0 && Psychic_Power - 10 > 0)
        {
            return true;
        }
        else if (Psychic_Power - 15 < 0)
        {
            return false;
        }
        else
        {
            Psychic_Power -= 15;
            Variable++;
            return true;
        }
    }

private:
    int Blood_Volume;
    int Psychic_Power;
    int PBlood_Volume;
    int PPsychic_Power;
    int Variable;
    int Gold;
    int x, y; //当前角色坐标
    IMAGE leftp1[4], leftp2[4];//创建一个IMAGE数组存储图片信息
    IMAGE rightp1[4], rightp2[4];
    IMAGE Magic_Arts1[13], BMagic_Arts1[13];
    IMAGE Magic_Arts2[13], BMagic_Arts2[13];
    IMAGE cover, stand, Bstand, background, battle_stand, Bbattle_stand;

    //战斗过程中角色位置
    int x1, y1;

    //法术状态
    int state1, state2;

    //法术施加对象位置
    int xs1, ys1;
    int xs2, ys2;
};

class enemy1 {
public:
    enemy1()
    {
        Blood_Volume = 100;

        state = 0;

        Variable = 0;

        x = 700;
        y = 90;

        x1 = x;
        y1 = y;

        for (int i = 1; i < 11; i++)
        {
            char Bpath[30], path[30];
            sprintf(Bpath, ".\\enemy\\enemy1\\B%d.png", i);
            sprintf(path, ".\\enemy\\enemy1\\%d.png", i);
            loadimage(&_Benemy1[i - 1], Bpath);
            loadimage(&_enemy1[i - 1], path);
        }
    }

    void CVariable()
    {
        Variable++;
    }

    void fresh()
    {
        Blood_Volume = 100;
        Variable = 0;
    }

    int putBlood_Volume()
    {
        return Blood_Volume;
    }

    int putV()
    {
        return Variable;
    }

    void paint2()
    {
        if (x1 != 100)
        {
            x1 -= 30;
        }
        if (y1 != 200)
        {
            y1 += 10;
        }
        makephototransparent(x1, y1, _Benemy1[state / 3], _enemy1[state / 3]);
        if (x1 == 100 && y1 == 200)
        {
            Variable++;
            x1 = x;
            y1 = y;
        }
    }

    void reduce1()
    {
        Blood_Volume -= 20;
    }

    void reduce2()
    {
        Blood_Volume -= 40;
    }

    void paint()
    {
        if (Blood_Volume <= 0)
        {
            return;
        }

        makephototransparent(x, y, _Benemy1[state / 3], _enemy1[state / 3]);
        settextstyle(20, 0, "微软雅黑");
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        char arr[30];
        sprintf(arr, "血量：%d", Blood_Volume);
        outtextxy(730, 85, arr);
    }

    void update()
    {
        state++;
        if (state == 30)
        {
            state = 0;
        }
    }
private:
    int state;
    int x, y;
    int x1, y1;
    int Blood_Volume;
    int Variable;
    IMAGE _enemy1[10], _Benemy1[10];
};

class enemy2 {
public:
    enemy2()
    {
        Blood_Volume = 100;

        state = 0;

        Variable = 0;

        x = 800;
        y = 170;

        x1 = x;
        y1 = y;

        for (int i = 1; i < 11; i++)
        {
            char Bpath[30], path[30];
            sprintf(Bpath, ".\\enemy\\enemy2\\B%d.png", i);
            sprintf(path, ".\\enemy\\enemy2\\%d.png", i);
            loadimage(&_Benemy2[i - 1], Bpath);
            loadimage(&_enemy2[i - 1], path);
        }
    }

    void CVariable()
    {
        Variable++;
    }

    void fresh()
    {
        Blood_Volume = 100;
        Variable = 0;
    }

    int putBlood_Volume()
    {
        return Blood_Volume;
    }

    int putV()
    {
        return Variable;
    }

    void paint2()
    {
        if (x1 != 100)
        {
            x1 -= 35;
        }
        if (y1 != 200)
        {
            y1 += 2;
        }
        makephototransparent(x1, y1, _Benemy2[state / 3], _enemy2[state / 3]);
        if (x1 == 100 && y1 == 200)
        {
            Variable++;
            x1 = x;
            y1 = y;
        }
    }

    void reduce1()
    {
        Blood_Volume -= 20;
    }

    void reduce2()
    {
        Blood_Volume -= 40;
    }

    void paint()
    {
        if (Blood_Volume <= 0)
        {
            return;
        }

        makephototransparent(x, y, _Benemy2[state / 3], _enemy2[state / 3]);
        settextstyle(20, 0, "微软雅黑");
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        char arr[30];
        sprintf(arr, "血量：%d", Blood_Volume);
        outtextxy(850, 170, arr);
    }

    void update()
    {
        state++;
        if (state == 30)
        {
            state = 0;
        }
    }
private:
    int state;
    int x, y;
    int x1, y1;
    int Blood_Volume;
    int Variable;
    IMAGE _enemy2[10], _Benemy2[10];
};

class enemy3 {
public:
    enemy3()
    {
        Blood_Volume = 100;

        state = 0;

        Variable = 0;

        x = 730;
        y = 250;

        x1 = x;
        y1 = y;

        for (int i = 1; i < 11; i++)
        {
            char Bpath[30], path[30];
            sprintf(Bpath, ".\\enemy\\enemy3\\B%d.png", i);
            sprintf(path, ".\\enemy\\enemy3\\%d.png", i);
            loadimage(&_Benemy3[i - 1], Bpath);
            loadimage(&_enemy3[i - 1], path);
        }
    }

    void CVariable()
    {
        Variable++;
    }

    void fresh()
    {
        Blood_Volume = 100;
        Variable = 0;
    }

    int putBlood_Volume()
    {
        return Blood_Volume;
    }

    int putV()
    {
        return Variable;
    }

    void paint2()
    {
        if (x1 != 100)
        {
            x1 -= 70;
        }
        if (y1 != 200)
        {
            y1 -= 5;
        }
        makephototransparent(x1, y1, _Benemy3[state / 3], _enemy3[state / 3]);
        if (x1 == 100 && y1 == 200)
        {
            Variable++;
            x1 = x;
            y1 = y;
        }
    }

    void reduce1()
    {
        Blood_Volume -= 20;
    }

    void reduce2()
    {
        Blood_Volume -= 40;
    }

    void paint()
    {
        if (Blood_Volume <= 0)
        {
            return;
        }

        makephototransparent(x, y, _Benemy3[state / 3], _enemy3[state / 3]);
        char arr[30];
        settextstyle(20, 0, "微软雅黑");
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        sprintf(arr, "血量：%d", Blood_Volume);
        outtextxy(740, 220, arr);
    }

    void update()
    {
        state++;
        if (state == 30)
        {
            state = 0;
        }
    }
private:
    int state;
    int x, y;
    int x1, y1;
    int Blood_Volume;
    int Variable;
    IMAGE _enemy3[10], _Benemy3[10];
};

class decoration {
public:
    decoration()
    {
        state1 = 0;
        state2 = 0;
        
        x1 = 0;
        y1 = 470;

        x2 = 70;
        y2 = 470;

        for (int i = 1; i < 3; i++)
        {
            char path[30], Bpath[30];
            sprintf(path, ".\\other\\art%d.png", i);
            sprintf(Bpath, ".\\other\\Bart%d.png", i);
            loadimage(&art1[i - 1], path);
            loadimage(&Bart1[i - 1], Bpath);
        }

        for (int i = 1; i < 3; i++)
        {
            char path[30], Bpath[30];
            sprintf(path, ".\\other\\art%d.png", i);
            sprintf(Bpath, ".\\other\\Bart%d.png", i);
            loadimage(&art2[i - 1], path);
            loadimage(&Bart2[i - 1], Bpath);
        }
    }

    void paint()
    {
        makephototransparent(x1, y1, Bart1[state1], art1[state1]);
        makephototransparent(x2, y2, Bart2[state2], art2[state2]);
    }

    void update1(int a)
    {
        if (a == 1)
        {
            state1 = 1;
        }
        else
        {
            state1 = 0;
        }
    }

    void update2(int a)
    {
        if (a == 1)
        {
            state2 = 1;
        }
        else
        {
            state2 = 0;
        }
    }

private:
    int state1;
    int state2;
    int x1, y1;
    int x2, y2;
    IMAGE art1[2], Bart1[2];
    IMAGE art2[2], Bart2[2];
};

gamebackground war_background("war_background.png");
role r;
enemy1 R;
enemy2 RR;
enemy3 RRR;
decoration d;

void makephototransparent(int x, int y, IMAGE a, IMAGE b)
{
	//横坐标, 纵坐标, 黑白图, 黑熊图
	putimage(x, y, &a, SRCAND);
	putimage(x, y, &b, SRCPAINT);
}
//原理：黑为0， 白为1，任意颜色与黑按位或均不变，
//                     任意颜色与白按位与均不变，
//                     任意颜色与黑按位与均为黑

void menu()
{
    mciSendString("open .\\music\\menu.wav", nullptr, 0, nullptr);

    mciSendString("play .\\music\\menu.wav", nullptr, 0, nullptr);

    //加载菜单背景图
    IMAGE background;
    loadimage(&background, ".//menu//background.png", 960, 540);
    putimage(0, 0, &background);

    //设置字体特点
    settextstyle(50, 20, "微软雅黑");
    setbkmode(TRANSPARENT);

    ExMessage p1;//接受鼠标信息
    while (1)
    {
        peekmessage(&p1, EX_MOUSE);
        if (p1.x > 400 && p1.x < 560 && p1.y > 250 && p1.y < 300)
        {
            settextcolor(WHITE);
        }
        else
        {
            settextcolor(BLACK);
        }
        outtextxy(400, 250, "开始游戏");

        if (p1.x > 400 && p1.x < 560 && p1.y > 310 && p1.y < 360)
        {
            settextcolor(WHITE);
        }
        else
        {
            settextcolor(BLACK);
        }
        outtextxy(400, 310, "退出游戏");
        //退出游戏
        if (p1.x > 400 && p1.x < 560 && p1.y > 310 && p1.y < 360 && p1.lbutton)
        {
            exit(0);
        }
        //开始游戏
        if (p1.x > 400 && p1.x < 560 && p1.y > 250 && p1.y < 300 && p1.lbutton)
        {
            mciSendString("stop .\\music\\menu.wav", nullptr, 0, nullptr);
            mciSendString("closs .\\music\\menu.wav", nullptr, 0, nullptr);
            r.move();
        }
    }
}

void select_aim1()
{
    ExMessage p1;
    while (1)
    {
        peekmessage(&p1);
        if (p1.x > 700 && p1.x < 842 && p1.y > 90 && p1.y < 233 && p1.lbutton)
        {
            if (r.Psychic_Power_update1())
            {
                r.update1(700, 90);
                mciSendString("close .\\music\\art1.wav", nullptr, 0, nullptr);
                mciSendString("open .\\music\\art1.wav", nullptr, 0, nullptr);
                mciSendString("play .\\music\\art1.wav", nullptr, 0, nullptr);
                R.reduce1();
            }
            break;
        }
        else if (p1.x > 800 && p1.x < 942 && p1.y > 170 && p1.y < 313 && p1.lbutton)
        {
            if (r.Psychic_Power_update1())
            {
                r.update1(800, 170);
                mciSendString("close .\\music\\art1.wav", nullptr, 0, nullptr);
                mciSendString("open .\\music\\art1.wav", nullptr, 0, nullptr);
                mciSendString("play .\\music\\art1.wav", nullptr, 0, nullptr);
                RR.reduce1();
            }
            break;
        }
        else if (p1.x > 730 && p1.x < 872 && p1.y > 250 && p1.y < 393 && p1.lbutton)
        {
            if (r.Psychic_Power_update1())
            {
                r.update1(730, 250);
                mciSendString("close .\\music\\art1.wav", nullptr, 0, nullptr);
                mciSendString("open .\\music\\art1.wav", nullptr, 0, nullptr);
                mciSendString("play .\\music\\art1.wav", nullptr, 0, nullptr);
                RRR.reduce1();
            }
            break;
        }
    }
}

void select_aim2()
{
    ExMessage p1;
    while (1)
    {
        peekmessage(&p1);
        if (p1.x > 700 && p1.x < 842 && p1.y > 90 && p1.y < 233 && p1.lbutton)
        {
            if (r.Psychic_Power_update2())
            {
                r.update2(700, 90);
                mciSendString("close .\\music\\art2.wav", nullptr, 0, nullptr);
                mciSendString("open .\\music\\art2.wav", nullptr, 0, nullptr);
                mciSendString("play .\\music\\art2.wav", nullptr, 0, nullptr);
                R.reduce2();
            }
            break;
        }
        else if (p1.x > 800 && p1.x < 942 && p1.y > 170 && p1.y < 313 && p1.lbutton)
        {
            if (r.Psychic_Power_update2())
            {
                r.update2(800, 170);
                mciSendString("close .\\music\\art2.wav", nullptr, 0, nullptr);
                mciSendString("open .\\music\\art2.wav", nullptr, 0, nullptr);
                mciSendString("play .\\music\\art2.wav", nullptr, 0, nullptr);
                RR.reduce2();
            }
            break;
        }
        else if (p1.x > 730 && p1.x < 872 && p1.y > 250 && p1.y < 393 && p1.lbutton)
        {
            if (r.Psychic_Power_update2())
            {
                r.update2(730, 250);
                mciSendString("close .\\music\\art2.wav", nullptr, 0, nullptr);
                mciSendString("open .\\music\\art2.wav", nullptr, 0, nullptr);
                mciSendString("play .\\music\\art2.wav", nullptr, 0, nullptr);
                RRR.reduce2();
            }
            break;
        }
    }
}

void mouseupdate()
{
    ExMessage p1;
    peekmessage(&p1);
    if (p1.x > 0 && p1.x < 60 && p1.y > 470 && p1.y < 540 && p1.lbutton)
    {
        d.update1(1);
        select_aim1();
    }
    else if (p1.x > 0 && p1.x < 60 && p1.y > 470 && p1.y < 540)
    {
        d.update1(1);
    }
    else if (p1.x > 70 && p1.x < 130 && p1.y > 470 && p1.y < 540 && p1.lbutton)
    {
        d.update2(1);
        select_aim2();
    }
    else if (p1.x > 70 && p1.x < 130 && p1.y > 470 && p1.y < 540)
    {
        d.update2(1);
    }
    else
    {
        d.update1(0);
        d.update2(0);
    }
}

void Battle()
{
    mciSendString("open .\\music\\battle.wav", nullptr, 0, nullptr);

    mciSendString("play .\\music\\battle.wav", nullptr, 0, nullptr);

    IMAGE loss, Bloss, pass, Bpass;
    loadimage(&loss, ".\\other\\loss.png");
    loadimage(&Bloss, ".\\other\\Bloss.png");
    loadimage(&pass, ".\\other\\pass.png");
    loadimage(&Bpass, ".\\other\\Bpass.png");
    while (1)
    {
        if (R.putBlood_Volume() <= 0 && RR.putBlood_Volume() <= 0 && RRR.putBlood_Volume() <= 0)
        {
            mciSendString("stop .\\music\\battle.wav", nullptr, 0, nullptr);
            mciSendString("close .\\music\\battle.wav", nullptr, 0, nullptr);

            cleardevice();
            makephototransparent(220, 200, Bpass, pass);
            Sleep(1000);

            // 重置角色和敌人的状态
            r.fresh_start();
            R.fresh();
            RR.fresh();
            RRR.fresh();

            // 返回主菜单
            menu();
            break;
        }

        if ((r.putBlood_Volume() <= 0 || r.putPsychic_Power() < 10) && (r.putstate1() == -1 && r.putstate2() == -1))
        {
            mciSendString("stop .\\music\\battle.wav", nullptr, 0, nullptr);
            mciSendString("close .\\music\\battle.wav", nullptr, 0, nullptr);

            cleardevice();
            war_background.paint();
            r.paint();
            R.paint();
            RR.paint();
            RRR.paint();
            d.paint();
            Sleep(3000);
            settextstyle(20, 0, "微软雅黑");
            setbkmode(TRANSPARENT);
            settextcolor(WHITE);
            cleardevice();
            makephototransparent(220, 200, Bloss, loss);
            outtextxy(350, 200, "获得提升：生命+100 灵力+100");
            Sleep(1000);
            r.increase();
            r.fresh();
            R.fresh();
            RR.fresh();
            RRR.fresh();
            r.move();
            break;
        }

        BeginBatchDraw();
        cleardevice();
        war_background.paint();
        r.paint();
        R.paint();
        RR.paint();
        RRR.paint();
        d.paint();
        mouseupdate();
        R.update();
        RR.update();
        RRR.update();
        Sleep(15);
        if (r.putV() != R.putV() && R.putV() == RR.putV() && RR.putV() == RRR.putV())
        {
            cleardevice();
            war_background.paint();
            r.paint();
            if (r.putstate1() == -1 && r.putstate2() == -1)
            {
                if (R.putBlood_Volume() > 0)
                {
                    R.paint2();
                }
                else
                {
                    R.CVariable();
                }
            }
            else
            {
                R.paint();
            }
            RR.paint();
            RRR.paint();
            d.paint();
            R.update();
            RR.update();
            RRR.update();
            Sleep(50);
            if (R.putV() != RR.putV() && R.putBlood_Volume() > 0)
            {
                r.reduce1();
            }
        }
        else if (r.putV() == R.putV() && R.putV() != RR.putV() && RR.putV() == RRR.putV())
        {
            cleardevice();
            war_background.paint();
            r.paint();
            R.paint();
            if (RR.putBlood_Volume() > 0)
            {
                RR.paint2();
            }
            else
            {
                RR.CVariable();
            }
            RRR.paint();
            d.paint();
            R.update();
            RR.update();
            RRR.update();
            Sleep(50);
            if (RR.putV() != RRR.putV() && RR.putBlood_Volume() > 0)
            {
                r.reduce2();
            }
        }
        else if (r.putV() == R.putV() && R.putV() == RR.putV() && RR.putV() != RRR.putV())
        {
            cleardevice();
            war_background.paint();
            r.paint();
            R.paint();
            RR.paint();
            if (RRR.putBlood_Volume() > 0)
            {
                RRR.paint2();
            }
            else
            {
                RRR.CVariable();
            }
            d.paint();
            R.update();
            RR.update();
            RRR.update();
            Sleep(50);
            if (RR.putV() == RRR.putV() && RRR.putBlood_Volume() > 0)
            {
                r.reduce3();
            }
        }
        EndBatchDraw();
    }
}

int main()
{
	initgraph(960, 540);
    menu();
    Battle();
	closegraph();
	return 0;
}