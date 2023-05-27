import matplotlib.pyplot as plt

tab = [[], [], []]
for i in range(3):
    nom = ["recuit.out", "swaps.out", "desc.out"][i]
    fic = open(nom, 'r')
    for ligne in fic:
        tab[i].append(float(ligne[0:-1]))
plt.plot(tab[0])
plt.plot(tab[1])
plt.plot(tab[2])
#print(len(tab[2]))
#plt.ylabel('some numbers')
plt.show()
plt.savefig("figure")
