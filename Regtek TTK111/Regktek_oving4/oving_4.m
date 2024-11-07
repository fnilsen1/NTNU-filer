%G = tf([1],[1 0]);
%K = tf([1],[1]);
%N = 1/(1+G*K);
%M = G*K/(1+G*K);
%NG = N*G;

%hold on;

%bode(N, 'g');
%bode(NG, 'r');
%bode(M, 'c');
%bode(G, 'b');
%bode(K, 'k');
%legend('N (Grønn)', 'M (Lyseblå)', 'NG (Rød)', 'G (Blå)', 'K (Svart)');
%hold off;

%L = tf(1,[1 1 0]);
%nyquist(L);
%axis([-2,2,-2,2]);

L = tf([2],[3 6 3 0]);
margin(L);