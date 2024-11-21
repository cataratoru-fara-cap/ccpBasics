#include <iostream>
class complex {
    private: //variables de la classe
        double re;
        double im;
   
    public:
        complex() {};// constructeur sans parametres
        
        complex(double param_re, double param_im) {
        //constructeur
        // initialise les membres de la classe avec des valeurs et alloue de la memoire pour les membres
            this->re=param_re; //re=param_re ou (*this).re, plus tard
            this->im=param_im;//im=param_im
        }
        double getRe(){//methode: getter
            return re;
        }
        double getIm(){ //methode: getter
            return im;
        }
        complex complex_conjugate() { //methode – le conjugué d’un nombre complexe
            complex conjugate(re,-im);//objet de type complex
                return conjugate;
        } 
        
        static complex_adition (complex num_1, complex num_2){
            complex num_3(num_1.getRe + num_2.getRe(), num_1.getIm() + num_2.getIm() );
            return num_3;
        }
        static complex complex_norme (complex num){
            double num_3 = num.getRe() * num.getRe() + num.getIm() * num.getIm();
            return num_3;
        }
        complex complex_multiplication(complex num_1){
            complex num_3(num_1.getRe() * this->re, num_1.getIm() * this->im );
            return num_3;
        }
};