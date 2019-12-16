cc -o generateABST generateABST.c tree.c -I.
valgrind ./generateABST
rm generateABST