#ifndef _ARG3_COLLECTIONS_H_
#define _ARG3_COLLECTIONS_H_

#include <map>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

namespace arg3
{
    //namespace collections
    //{
        template<typename K, typename V>
        string join(map<K, V> collection, const string &divider = ",", function<const pair<K,V> &()> op = [] (const pair<K,V> &e) { e.first; })
        {
            list<K> keys;
            ostringstream buf;

            transform(collection.begin(), collection.end(), keys.begin(), op);

            if(keys.size() > 0) {
                ostream_iterator<K> it(buf, divider);

                copy(keys.begin(), keys.end()-1, it);

                buf << keys.last();
            }


            return buf.str();
        }

        template<typename T>
        string join(initializer_list<T> list, const string &delimiter = ",")
        {
            ostringstream buf;

            if(list.size() > 0) {
                ostream_iterator<T> it(buf, delimiter);

                copy(list.begin(), list.end()-1, it);

                buf << list.end()-1;
            }

            return buf.str();
        }

        template<typename T>
        string join(vector<T> list, const string &divider = ",")
        {
        	ostringstream buf;

            if(list.size() > 0) {
                ostream_iterator<T> it(buf, divider);

                copy(list.begin(), list.end()-1, it);

                buf << list[list.size()-1];
            }

        	return buf.str();
        }
    //}
}

#endif
