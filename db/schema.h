#ifndef _ARG3_DB_SCHEMA_H_
#define _ARG3_DB_SCHEMA_H_

#include <string>
#include <vector>
#include "sqldb.h"

using namespace std;

namespace arg3
{

    namespace db
    {

        class column_definition
        {
        	friend class schema;
        private:
            string m_name;
            bool m_pk;
            int m_type;
        public:
            string name() const;

            bool pk() const;

            int type() const;
        };

        ostream &operator<<(ostream &os, const column_definition &def);

        class schema
        {
        private:
            vector<column_definition> m_columns;

        public:
            schema();

            schema(sqldb db, const string &tablename);

            void init(sqldb db, const string &tablename) ;

            vector<column_definition> columns() const;

            vector<string> column_names() const;

            vector<string> primary_keys() const;

            column_definition operator[](size_t index) const;

            bool is_valid() const;
        };
    }

}

#endif
