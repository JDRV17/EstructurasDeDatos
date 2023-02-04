#Nombre: Juan Diego Rojas Valdés (Juan Rojas)
#Código: 8983626
#Punto 1)
mat1=[[11,23,76,34,11],[14,30,92,30,101],[12,45,58,92,22],[74,56,49,56,100],[99,5,28,47,99]]
def verificarDiagonales(mat):
    length=len(mat)
    diag1=[]
    for i in range (length):
        for j in range (length):
            if i==j:
                diag1.append(mat[i][j])
    diag2=[]
    for i in range (length):
        for j in range (length):
            if i==j:
                diag2.append(mat[i][(length-j)-1])    
    if diag1==diag2:
        flag= True
    else:
        flag= False   
    return "1", flag
print(verificarDiagonales(mat1))

#Punto 2)
list1=[42,12,90,90,12,42]
list2=[42,12,90,90,12,45]
def esCapicua(list):
    length=len(list)
    for i in range(length):
        if list[i]!=list[(length-1)-i]:
            flag= False
            break
        else:
            flag= True
    return "2", flag        
print(esCapicua(list1))
print(esCapicua(list2))

#Punto 3)
#Numeral a)
list3=[40,10,22,12,33,33,33]
list4=[41,22,31,15,13,12,33,19]
def diferenciaListas(list1,list2):
    length1=len(list1)
    length2=len(list2)
    dif=[]
    for i in range (length1):
        #print(list1.count(list1[i]))
        if list1[i] not in list2:
            dif.append(list1[i])
        else:
            if list1.count(list1[i])-list2.count(list1[i])>1:
                for j in range (list1.count(list1[i])-list2.count(list1[i])):
                    dif.append(list1[i]) 
                    
    return "3a", dif
print(diferenciaListas(list3,list4))

#Numeral b)
#def lectImpres():
  #  veces=input()
   # for i in range (veces):
    #    mat=input()
#lectImpres()

#Punto 4
N=100
def mostrarPrimos(N):
    print("Números primos del 1 al ",N,":")
    primos=[]
    primosdobles=[]
    primosdoblesreales=[]
    for i in range (N):
        cont=0
        for j in range (i):
            if j!=0:
                if i%j==0:
                    cont=cont+1
        if cont==1:
            primos.append(i)
            print("--->",i)
            string=str(i)
            num=list(string)
            suma=0
            k=0
            while k<=(len(num)-1):
                suma=suma+(int)(num[k])
                k=k+1
            for l in range(suma):
                cont2=0
                if l!=0:
                    if suma%l==0:
                        cont2=cont2+1
                if cont2==1:
                    primosdobles.append(i)
    for i in primosdobles:
        if primosdobles.count(i)==1:
            primosdoblesreales.append(i)
    print("Los números primos cuya suma de sus dígitos también son números primos son los siguientes: ",primosdoblesreales)
mostrarPrimos(N)

#Punto 5)
matriz=[[1,0,0,0,0,4,0,5],
        [0,0,0,0,0,0,4,7],
        [2,2,0,0,9,0,1,0],
        [0,0,0,0,0,0,0,0],
        [0,0,8,1,0,7,0,0],
        [0,0,0,0,0,0,0,0],
        [3,0,0,0,0,6,0,2],
        [4,4,7,0,0,0,0,0],
        [0,9,0,8,0,7,0,6]]
disp={0:[(0,1),(5,4),(7,5)],
      1:[(6,4),(7,7)],
      2:[(0,2),(1,2),(4,9),(6,1)],
      4:[(2,8),(3,1),(5,7)],
      6:[(0,3),(5,6),(7,2)],
      7:[(0,4),(1,4),(2,7)],
      8:[(1,9),(3,8),(5,7),(7,6)]}
par=[(0,0),(8,3),(3,5),(7,2),(4,3),(4,6)]

def sumarValoresMatriz(mat, par):
    matriz=[]
    lista=[]
    lugar=[]
    numero=[]
    keys=list(mat)
    for i in range(max(keys)+1):
        #print(i)
        if i in mat:
            for j in range (len(mat[i])):
                lugar.append(mat[i][j][0])
                #print(max(lugar))
                numero.append(mat[i][j][1])
                if i== 0:
                    for k in range (8):
                        print(mat[i][j][0])
                        while len(lista)<8:
                            if mat[i][j][0] == k:
                                lista.append(mat[i][j][1])
                            else:
                                lista.append(0)


                            
        
    print(lista)
    #print(max(lugar))
    #print(numero)
sumarValoresMatriz(disp,par)

