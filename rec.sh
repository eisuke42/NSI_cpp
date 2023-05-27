g++ tests.cpp -o tests
./tests > test1.in

g++ recuit.cpp -o recuit
./recuit < test1.in > recuit.out
echo -n "recuit simulé : "
tail -n 1 recuit.out

g++ swaps.cpp -o swaps 
./swaps < test1.in > swaps.out
echo -n "swaps : "
tail -n 1 swaps.out

g++ desc.cpp -o desc
./desc < test1.in > desc.out
echo -n "descente locale : "
tail -n 1 desc.out

python3 graphique.py
