#include <iostream>

template < typename T >
void my_swap ( T & first , T & second ) 

{
    T temp(first) ; 
    first = second ;
    second = temp ;

}

template < class ElementType > 
void bubbleSort(ElementType * arr, size_t arrSize)

{

    for(size_t i = 0; i < arrSize - 1; ++i) 
        for(size_t j = 0; j < arrSize - 1; ++j)
            if (arr[j + 1] < arr[j]) 
                my_swap ( arr[j] , arr[j+1] ) ;

}

template < typename ElementType >
void out_array ( const ElementType * arr , size_t arrSize )

{

    for ( size_t i = 0 ; i < arrSize ; ++i )
       std::cout << arr[i] << ' ' ;
    std::cout << std::endl ;

}


int main ()

{
    const size_t n = 7 ;
    int v1 [ n ] = { 4 , 12 , 3, 5 , 6 , 1 , 0} ;
    double v2 [ n ] = { 8.99 , 76.3 , 36.6 , 404.3 , 12.0 , 24.5 , 32.12 } ;
    std::cout << "Список начальных вектороров:\n" ;
    out_array ( v1 , n ) ;
    out_array ( v2 , n ) ;

    bubbleSort ( v1 , n ) ;
    bubbleSort ( v2 , n ) ;

    std::cout << "Список сортированных векторов:\n" ;
    out_array ( v1 , n ) ;
out_array ( v2 , n ) ;

}
