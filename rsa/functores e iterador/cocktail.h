#ifndef COCKTAIL_H
#define COCKTAIL_H

//template <class A>
class cocktail
{
    public:
        int *arreglo;

        cocktail( int *numeros ):numeros(arreglo) {};
        int* ascendente(int tam,bool(*p)(int,int)){
            int *ini=numeros;
            int *fin=(numeros+tam-1);
            int *A=ini;
            int *B=fin;bool swapC=1;
            ini=ini+1;fin=fin-1;
            while(swapC){
                if(ini<=fin){
                    if(A<=fin){
                        if(p(*(A+1),*A)){//recorrer todos los numeros
                            swapP(A,(A+1));
                        }A++;
                    }
                else{
                    if(B>=ini){
                        if(p(*B,*(B-1))){
                            swapP(B,(B-1));}
                            B--;}
                        else{
                            fin--;B=fin;
                            ini++;A=ini;}
                    }
                }
            else{swapC=0;
                }
            }
        }

};

#endif // COCKTAIL_H
