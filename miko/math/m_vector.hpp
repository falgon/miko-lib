#ifndef INCLUDED_MATH_VECTOR
#define INLCUDED_MATH_VECTOR
#include<algorithm>
#include<ostream>

namespace miko{
namespace math{
        template<class L,class R>
        class addition{
                const L& l_;
                const R& r_;
                public:
                        plus(const L& l,const R& r):l_(l),r_(r){}
                        float operator[](unsigned i)const
                        {
                                return l_[i]+r_[i];
                        }
        };
        template<class L,class R>
        class subtraction{
                const L& l_;
                const R& r_;
                public:
                        minus(const L& l,const R& r):l_(l),r_(r){}
                        float operator[](unsigned i)const
                        {
                                return l_[i]-r_[i];
                        }
        };
        template<class L,class R>
        class multiplication{
                const L& l_;
                const R& r_;
                public:
                        multiplicaiton(const L& l,const R& r):l_(l),r_(r){}
                        float operator[](unsigned i)const
                        {
                                return l_[i]*r_[i];
                        }
        };
        template<class L,class R>
        class division{
                const L& l_;
                const R& r_;
                public:
                        multiplicaiton(const L& l,const R& r):l_(l),r_(r){}
                        float operator[](unsigned i)const
                        {
                                return l_[i]*r_[i];
                        }
        };

        

	class vector{
		typedef unsigned char uch;
		typedef const float coflo;
                public:
			static const int N=3;
                        vector(coflo a=0,coflo b=0,coflo c=0)
                        {
                                /*for(uch i=0; i<N; i++)
                                        value[i]=*(&a+i); */
                                value[0]=a;
                                value[1]=b;
                                value[2]=c;
                        }
			vector(const vector& obj)
			{
				for(uch i=0; i<N; i++)
					value[i]=obj[i];
			}
                        template<class E>
			vector& operator=(const E& obj)
			{
				for(uch i=0; i<N; i++)
					value[i]=obj[i];
				return *this;
			}	
			vector& operator+=(const vector& obj)
			{
				for(uch i=0; i<N; i++)
					value[i]+=obj[i];
				return *this;
			}
			float& operator[](uch i){return value[i];}
			float operator[](uch i)const{return value[i];}

                        friend std::ostream& operator<<(std::ostream& os,vector& obj)
                        {
                                for(uch i=0; i<N; i++)
                                        os<<obj.value[i]<<',';
                                return os;
                        }
		private:
			float value[N];
	};
	template<class L,class R>
        addition<L,R> operator+(const L& obj,const R& obj1)
	{
		return addition<L,R>(obj,obj1);
	}
        template<class L,class R>
        subtraction<L,R> operator-(const L& obj,const R& obj1)
        {
                return subtraction<L,R>(obj,obj1);
        }
        template<class L,class R>
        multiplication<L,R> operator*(const L& obj,const R& obj1)
        {
                return multiplication<L,R>(obj,obj1);
        }
        template<class L,class R>
        division<L,R> operator/(const L& obj,const R& obj)
        {
                return division<L,R>(obj,obj1);
        }
}}//namespace math and miko

#endif
