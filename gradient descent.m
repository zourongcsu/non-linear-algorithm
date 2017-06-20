clc;
syms x1 x2 f e k;
x = [x1;x2];
f = 2*x1^2 + x2^2;
x = [1;1];
e = 0.1;
%第一步，计算函数f对变量x1和x2的偏导数
p1 = -diff(f,x1);
p2 = -diff(f,x2);
flag = 1;
while(flag)
    %第二步，更新雅克比矩阵
    p1_t = subs(p1,x1,x(1));
    p2_t = subs(p2,x2,x(2));
    P = [p1_t;p2_t];
    if(norm(P) > e)
        %第三步，求取h_next对k的倒数，解出步长k的值
        xk = x + k*P;
        h = subs(f,x1,xk(1));
        h_next = subs(h,x2,xk(2));
        h_end = diff(h_next,k);
        delta = solve(h_end);
        %第四步，更新x的取值
        x = x + delta*P
    else
        flag = 0;
    end
    
end
