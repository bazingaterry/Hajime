#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;

struct point {
    int x;    //横坐标 
    int y;    //纵坐标 
    int step; //当前走了几步 
};

int main() {
    int n, i, j;
    point tmp, next;
    int maze[100][100];
    queue<point> q;
    for (cin >> n; n != 0; cin >> n) {
        while(q.size() != 0) q.pop();   //初始化清空队列 
        for (i = 0; i < n; i++) {      //读取迷宫 
            for (j = 0; j < n; j++)
                cin >> maze[i][j];
        }
        maze[0][0] = 1;               //读取起点，并放入队列 
        tmp.x = tmp.y = 0;
        tmp.step = 1;
        q.push(tmp);
        
        while(!q.empty()) {             //队列非空时 
            tmp = q.front();
            if (tmp.x == n - 1 && tmp.y == n - 1) break; //读到出口，跳出循环 
            if (tmp.x - 1 >= 0 && !maze[tmp.x - 1][tmp.y]) {  //向上试探路径 
                next.x = tmp.x - 1;
                next.y = tmp.y;
                next.step = tmp.step + 1;//记录成下一步并入队 
                q.push(next);
                maze[tmp.x - 1][tmp.y] = 1;//记录此处已经 不能走了，避免走回头路 
            }
            if (tmp.y - 1 >= 0 && !maze[tmp.x][tmp.y - 1]) {//向右试探路径 
                next.x = tmp.x;
                next.y = tmp.y - 1;
                next.step = tmp.step + 1;//记录成下一步并入队 
                q.push(next);
                maze[tmp.x][tmp.y - 1] = 1;//记录此处已经 不能走了，避免走回头路 
            }
            if (tmp.x + 1 < n && !maze[tmp.x + 1][tmp.y]) {//向下试探路径 
                next.x = tmp.x + 1;
                next.y = tmp.y;
                next.step = tmp.step + 1;//记录成下一步并入队 
                q.push(next);
                maze[tmp.x + 1][tmp.y] = 1;//记录此处已经 不能走了，避免走回头路 
            }
            if (tmp.y + 1 < n && !maze[tmp.x][tmp.y + 1]) {//向左试探路径 
                next.x = tmp.x;
                next.y = tmp.y + 1;
                next.step = tmp.step + 1;//记录成下一步并入队 
                q.push(next);
                maze[tmp.x][tmp.y + 1] = 1;//记录此处已经 不能走了，避免走回头路 
            }
            q.pop();//当前所处出队，继续下一步判断 
        }
        
        if (tmp.x == n - 1 && tmp.y == n - 1)//若读取到出口，输出当前步数 
            cout << q.front().step << endl;
        else
            cout << "0" << endl;
        
        
    }
}