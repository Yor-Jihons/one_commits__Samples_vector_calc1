#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>
#include<stack>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}

namespace Original{
    std::vector<int> CalcScalarMultiple( const std::vector<int>& orig, int scalar ){
        std::vector<int> res(orig.size());
        for( int i = 0; i < static_cast<int>(orig.size()); i++ ){
            res[i] = orig[i] * scalar;
        }
    return res;
    }

    std::vector<int> AddColumnVector( const std::vector<int>& v1, const std::vector<int>& v2 ){
        std::vector<int> res(v1.size());
        for( int i = 0; i < static_cast<int>(v1.size()); i++ ){
            res[i] = v1[i] + v2[i];
        }
    return res;
    }
}

int main( int argc, char** argv ){

    int n;
    cin >> n;

    std::vector<int> a(n);
    for( int i = 0; i < n; i++ ){
        cin >> a[i];
    }

    std::vector<int> b(n);
    for( int i = 0; i < n; i++ ){
        cin >> b[i];
    }

    // C = A + 2B
    std::vector<int> c = Original::AddColumnVector( a, Original::CalcScalarMultiple( b, 2 ) );

    for( int i = 0; i < n; i++ ){
        cout << c[i] << endl;
    }
return 0;
}
