#include <random>
#include <ctime>
#include <unistd.h>
using std::default_random_engine;
using std::uniform_int_distribution;
#define ROW 9
#define COL 9
#define NUMMIN 29 // 9*9数独初始化的最少数字
#define NUMMAX 57
class sudoku
{
//private:
public:
    int table[9][9];
    int constant[9][9];
    unsigned remain;

    void init();
    bool judge(size_t r, size_t c, unsigned val) const;
    void draw();
    void solve();
    void dfs(int x, int y, bool &last);
public:
    sudoku();
    void run();
};
bool sudoku::judge(size_t r, size_t c, unsigned val) const
{
    int hash[10];
    memset(hash, 0, sizeof(hash));
    for(size_t i = 0; i < 9; ++i)
    {
        if(table[r][i] != 0 && ++hash[table[r][i]] > 1)
            return false;
    }
    memset(hash, 0, sizeof(hash));
    for(size_t i = 0; i < 9; ++i)
    {
        if(table[i][c] != 0 && ++hash[table[i][c]] > 1)
            return false;
    }
    size_t subr = r / 3, subc = c / 3;
    memset(hash, 0, sizeof(hash));
    for(size_t i = subr * 3; i < subr * 3 + 3; ++i)
    {
        for(size_t j = subc * 3; j < subc * 3 + 3; ++j)
        {
            if(table[i][j] != 0 && ++hash[table[i][j]] > 1)
                return false;
        }
    }
    return true;
}
void sudoku::init()
{
    static default_random_engine e;
    e.seed(time(0));
    static uniform_int_distribution<unsigned> u1(NUMMIN, NUMMAX),
                                    u2(1, 9),
                                    u3(0, 8);
    unsigned init_num;
    init_num = u1(e);
    memset(table, 0, sizeof(table));
    memset(constant, 0, sizeof(constant));
    remain = ROW * COL;
    for(size_t i = 0; i < init_num;)
    {
        size_t r = u3(e), c = u3(e);
        unsigned val = u2(e);
        if(table[r][c] != 0)
            continue;
        table[r][c] = val;
        if(judge(r, c, val))
        {
            ++i;
        }
        else
            table[r][c] = 0;
    }
    remain -= init_num;
}
sudoku::sudoku()
{
    //memset(table, 0, sizeof(table));
    //remain = ROW * COL;
    init();
}
void sudoku::run()
{
    draw();
    char c;
    int x, y, currx, curry;
    getyx(stdscr, y, x);
    getyx(stdscr, curry, currx);
    while(remain > 0)
    {
        c = getch();
        //getyx(stdscr, curry, currx);
        if(c == 'w' || c == 'W')
        {
            if(curry == y)
                beep();
            else
            {
                curry -= 2;
                move(curry, currx);
            }
            continue;
        }
        if(c == 'a' || c == 'A')
        {
            if(currx == x)
                beep();
            else
            {
                currx -= 4;
                move(curry, currx);
            }
            continue;
        }
        if(c == 's' || c == 'S')
        {
            if(curry == y + 16)
                beep();
            else
            {
                curry += 2;
                move(curry, currx);
            }
            continue;
        }
        if(c == 'd' || c == 'D')
        {
            if(currx == x + 32)
                beep();
            else
            {
                currx += 4;
                move(curry, currx);
            }
            continue;
        }
        if(c >= '1' && c <= '9')
        {
            unsigned val = c - '0';
            size_t a = (currx - x) / 4,
                b = (curry - y) / 2;
            if(constant[b][a] != 0)
            {
                beep();
                continue;
            }
            bool add = false;
            int tmp = table[b][a];
            if(table[b][a] == 0)
                add = true;
            table[b][a] = val;
            if(judge(b, a, val))
            {
                if(add)
                    --remain;
                //table[b][a] = val;
                addch(c);
                move(curry, currx);
            }
            else
            {
                table[b][a] = tmp;
                beep();
            }
            continue;
        }
        if(c == 'q' || c == 'Q')
            break;
        if(c == 'r' || c == 'R')
        {
            init();
            draw();
            continue;
        }
        /*
        if(c == 'm' || c == 'M')
        {
            solve();
            draw();
            continue;
        }*/
        beep();
    }
}
/*
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
                |   |   |   |   |   |   |   |   |   |
                +---+---+---+---+---+---+---+---+---+
A(left),D(right),W(up),S(down),1~9(number),R(restart),Q(exit),M(answer)
*/
// 21 行 80 列
void sudoku::draw()
{
    clear();
    int y, x;
    getmaxyx(stdscr, y, x);
    int curry = (y - 21) / 2, currx = (x - 37) / 2;
    move(curry, currx);
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            addch('+');
            addch('-');
            addch('-');
            addch('-');
            move(curry + 1, currx);
            addch('|');
            if(table[i][j] != 0)
            {
                move(curry + 1, currx + 2);
                addch(table[i][j] + '0');
            }
            if(j == 8)
            {
                move(curry, currx + 4);
                addch('+');
                move(curry + 1, currx + 4);
                addch('|');
            }
            if(i == 8)
            {
                move(curry + 2, currx);
                addch('+');
                addch('-');
                addch('-');
                addch('-');
                if(j == 8)
                    addch('+');
            }
            currx += 4;
            move(curry, currx);
        }
        curry += 2;
        currx = (x - 37) / 2;
        move(curry, currx);
    }
    curry += 2;
    mvprintw(curry, (x - 80) / 2, "A(left),D(right),W(up),S(down),1~9(number),R(restart),Q(exit)");
    curry = (y - 21) / 2, currx = (x - 37) / 2;
    move(curry + 1, currx + 2);
}
void sudoku::dfs(int x, int y, bool &last)
{
    if(x == 9)
    {
        last = true;
        return;
    }
    if(y == 9)
    {
        dfs(x + 1, 0, last);
        return;
    }
    if(table[x][y] != 0)
    {
        dfs(x, y + 1, last);
        return;
    }
    for(int i = 1; i < 10; ++i)
    {
        //table[x][y] = i;
        if(judge(x, y, i))
        {
            table[x][y] = i;
            dfs(x, y + 1, last);
        }
        if(last)
            return;
        table[x][y] = 0;
    }
}
void sudoku::solve()
{
    memcpy(table, constant, sizeof(table));
    bool last = false;
    dfs(0, 0, last);
}
/*
            Welcome to Sudoku
Please enter s to start the game or q to exit game
              author: hhhuu
              version:0.0.1
*/
void init_scr()
{
    initscr();
    cbreak();
    noecho();
    int y, x;
    char c;
    getmaxyx(stdscr, y, x);
    mvprintw(y / 2 - 1, (x - 17) / 2, "Welcome to Sudoku");
    mvprintw(y / 2, (x - 50) / 2, "Please enter s to start the game or q to exit game");
    mvprintw(y / 2 + 1, (x - 13) / 2, "author: hhhuu");
    mvprintw(y / 2 + 2, (x - 13) / 2, "version:0.0.1");
    c = getch();
    while(c != 's')
    {
        if(c == 'q')
        {
            endwin();
            exit(0);
        }
        beep();
        c = getch();
    }
}
int main()
{
    init_scr();
    sudoku game;
    game.run();
    //char c = getch();
    endwin();
}
