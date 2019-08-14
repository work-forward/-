1、查找某个端口是否被占用

netstat -anp|grep 80

2、查看当前运行的进程

ps

3、查看所有子进程

pstree -p 6648

4、终止进程

kill -9 进程号：彻底杀死某个进程

ctrl-c: ( kill foreground process ) 发送 SIGINT 信号给前台进程组中的所有进程，强制终止程序的执行；

ctrl-z: ( suspend foreground process ) 发送 SIGTSTP 信号给前台进程组中的所有进程，常用于挂起一个进程，而并
非结束进程，用户可以使用使用fg/bg操作恢复执行前台或后台的进程。fg命令在前台恢复执行被挂起的进程
5、查找一个进程的所有子进程
ps -ef | grep gaiad | grep -v "grep" | awl '{print $2} // 得到进程pid
pstree -p 21492 ps mp 21492 -o THREAD,tid
---


