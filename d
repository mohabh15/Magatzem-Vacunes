[1mdiff --git a/cambra.cpp b/cambra.cpp[m
[1mindex 1844da9..e5f02a2 100644[m
[1m--- a/cambra.cpp[m
[1m+++ b/cambra.cpp[m
[36m@@ -80,7 +80,11 @@[m [mvoid cambra::comprimir()[m
 [m
 }[m
 [m
[31m-[m
[32m+[m[32mbool mirar_null(string a, string b)[m
[32m+[m[32m{[m
[32m+[m	[32mif(a=="NULL") return false;[m
[32m+[m	[32mreturn true;[m
[32m+[m[32m}[m
 void cambra::ordenar()[m
 //Pre: cert[m
 //Post: S’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats[m
[36m@@ -89,6 +93,9 @@[m [mvoid cambra::ordenar()[m
 	for(int i=0; i<cambra1.size(); ++i)[m
 	{[m
 		for(int j=0; i<cambra1.size(); ++i)[m
[32m+[m		[32m{[m
[32m+[m			[32msort(cambra1.begin(),cambra1.end(),mirar_null);[m
[32m+[m		[32m}[m
 	}[m
 [m
 }[m
