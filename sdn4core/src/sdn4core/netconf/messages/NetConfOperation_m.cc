//
// Generated file, do not edit! Created by nedtool 5.5 from sdn4core/netconf/messages/NetConfOperation.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "NetConfOperation_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace SDN4CoRE {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(NetConfOperation)

NetConfOperation::NetConfOperation(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
}

NetConfOperation::NetConfOperation(const NetConfOperation& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

NetConfOperation::~NetConfOperation()
{
}

NetConfOperation& NetConfOperation::operator=(const NetConfOperation& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation::copy(const NetConfOperation& other)
{
}

void NetConfOperation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
}

void NetConfOperation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
}

class NetConfOperationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperationDescriptor();
    virtual ~NetConfOperationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperationDescriptor)

NetConfOperationDescriptor::NetConfOperationDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

NetConfOperationDescriptor::~NetConfOperationDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation *>(obj)!=nullptr;
}

const char **NetConfOperationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConfOperationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConfOperationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConfOperationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConfOperationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation *pp = (NetConfOperation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation *pp = (NetConfOperation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation *pp = (NetConfOperation *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConfOperationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation *pp = (NetConfOperation *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConfOperationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConfOperationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation *pp = (NetConfOperation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_GetConfig)

NetConfOperation_GetConfig::NetConfOperation_GetConfig(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(133);

}

NetConfOperation_GetConfig::NetConfOperation_GetConfig(const NetConfOperation_GetConfig& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_GetConfig::~NetConfOperation_GetConfig()
{
}

NetConfOperation_GetConfig& NetConfOperation_GetConfig::operator=(const NetConfOperation_GetConfig& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_GetConfig::copy(const NetConfOperation_GetConfig& other)
{
    this->source = other.source;
    this->filter = other.filter;
}

void NetConfOperation_GetConfig::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->source);
    doParsimPacking(b,this->filter);
}

void NetConfOperation_GetConfig::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->source);
    doParsimUnpacking(b,this->filter);
}

const char * NetConfOperation_GetConfig::getSource() const
{
    return this->source.c_str();
}

void NetConfOperation_GetConfig::setSource(const char * source)
{
    this->source = source;
}

NetConfFilter& NetConfOperation_GetConfig::getFilter()
{
    return this->filter;
}

void NetConfOperation_GetConfig::setFilter(const NetConfFilter& filter)
{
    this->filter = filter;
}

class NetConfOperation_GetConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_GetConfigDescriptor();
    virtual ~NetConfOperation_GetConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_GetConfigDescriptor)

NetConfOperation_GetConfigDescriptor::NetConfOperation_GetConfigDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_GetConfig", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_GetConfigDescriptor::~NetConfOperation_GetConfigDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_GetConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_GetConfig *>(obj)!=nullptr;
}

const char **NetConfOperation_GetConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_GetConfigDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_GetConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int NetConfOperation_GetConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_GetConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "source",
        "filter",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int NetConfOperation_GetConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "filter")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_GetConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "NetConfFilter",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_GetConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_GetConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_GetConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_GetConfig *pp = (NetConfOperation_GetConfig *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_GetConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_GetConfig *pp = (NetConfOperation_GetConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_GetConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_GetConfig *pp = (NetConfOperation_GetConfig *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSource());
        case 1: {std::stringstream out; out << pp->getFilter(); return out.str();}
        default: return "";
    }
}

bool NetConfOperation_GetConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_GetConfig *pp = (NetConfOperation_GetConfig *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource((value)); return true;
        default: return false;
    }
}

const char *NetConfOperation_GetConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(NetConfFilter));
        default: return nullptr;
    };
}

void *NetConfOperation_GetConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_GetConfig *pp = (NetConfOperation_GetConfig *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getFilter()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("SDN4CoRE::NetConfOperation_Operation");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("SDN4CoRE::NetConfOperation_Operation"));
    e->insert(NETCONFOPERATION_OPERATION_NONE, "NETCONFOPERATION_OPERATION_NONE");
    e->insert(NETCONFOPERATION_OPERATION_MERGE, "NETCONFOPERATION_OPERATION_MERGE");
    e->insert(NETCONFOPERATION_OPERATION_REPLACE, "NETCONFOPERATION_OPERATION_REPLACE");
    e->insert(NETCONFOPERATION_OPERATION_CREATE, "NETCONFOPERATION_OPERATION_CREATE");
    e->insert(NETCONFOPERATION_OPERATION_DELETE, "NETCONFOPERATION_OPERATION_DELETE");
    e->insert(NETCONFOPERATION_OPERATION_REMOVE, "NETCONFOPERATION_OPERATION_REMOVE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("SDN4CoRE::NetConfOperation_ErrorOption");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("SDN4CoRE::NetConfOperation_ErrorOption"));
    e->insert(NETCONFOPERATION_ERROROPTION_STOPONERROR, "NETCONFOPERATION_ERROROPTION_STOPONERROR");
    e->insert(NETCONFOPERATION_ERROROPTION_CONTINUEONERROR, "NETCONFOPERATION_ERROROPTION_CONTINUEONERROR");
    e->insert(NETCONFOPERATION_ERROROPTION_ROLLBACKONERROR, "NETCONFOPERATION_ERROROPTION_ROLLBACKONERROR");
)

Register_Class(NetConfOperation_EditConfig)

NetConfOperation_EditConfig::NetConfOperation_EditConfig(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(119);

    this->defaultOperation = 0;
    this->errorOption = 0;
}

NetConfOperation_EditConfig::NetConfOperation_EditConfig(const NetConfOperation_EditConfig& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_EditConfig::~NetConfOperation_EditConfig()
{
}

NetConfOperation_EditConfig& NetConfOperation_EditConfig::operator=(const NetConfOperation_EditConfig& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_EditConfig::copy(const NetConfOperation_EditConfig& other)
{
    this->target = other.target;
    this->defaultOperation = other.defaultOperation;
    this->errorOption = other.errorOption;
}

void NetConfOperation_EditConfig::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->target);
    doParsimPacking(b,this->defaultOperation);
    doParsimPacking(b,this->errorOption);
}

void NetConfOperation_EditConfig::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->target);
    doParsimUnpacking(b,this->defaultOperation);
    doParsimUnpacking(b,this->errorOption);
}

const char * NetConfOperation_EditConfig::getTarget() const
{
    return this->target.c_str();
}

void NetConfOperation_EditConfig::setTarget(const char * target)
{
    this->target = target;
}

int NetConfOperation_EditConfig::getDefaultOperation() const
{
    return this->defaultOperation;
}

void NetConfOperation_EditConfig::setDefaultOperation(int defaultOperation)
{
    this->defaultOperation = defaultOperation;
}

int NetConfOperation_EditConfig::getErrorOption() const
{
    return this->errorOption;
}

void NetConfOperation_EditConfig::setErrorOption(int errorOption)
{
    this->errorOption = errorOption;
}

class NetConfOperation_EditConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_EditConfigDescriptor();
    virtual ~NetConfOperation_EditConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_EditConfigDescriptor)

NetConfOperation_EditConfigDescriptor::NetConfOperation_EditConfigDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_EditConfig", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_EditConfigDescriptor::~NetConfOperation_EditConfigDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_EditConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_EditConfig *>(obj)!=nullptr;
}

const char **NetConfOperation_EditConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_EditConfigDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_EditConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int NetConfOperation_EditConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_EditConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "target",
        "defaultOperation",
        "errorOption",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int NetConfOperation_EditConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "target")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "defaultOperation")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorOption")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_EditConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_EditConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *NetConfOperation_EditConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "SDN4CoRE::NetConfOperation_Operation";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"enum")) return "SDN4CoRE::NetConfOperation_ErrorOption";
            return nullptr;
        default: return nullptr;
    }
}

int NetConfOperation_EditConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_EditConfig *pp = (NetConfOperation_EditConfig *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_EditConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_EditConfig *pp = (NetConfOperation_EditConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_EditConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_EditConfig *pp = (NetConfOperation_EditConfig *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getTarget());
        case 1: return enum2string(pp->getDefaultOperation(), "SDN4CoRE::NetConfOperation_Operation");
        case 2: return enum2string(pp->getErrorOption(), "SDN4CoRE::NetConfOperation_ErrorOption");
        default: return "";
    }
}

bool NetConfOperation_EditConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_EditConfig *pp = (NetConfOperation_EditConfig *)object; (void)pp;
    switch (field) {
        case 0: pp->setTarget((value)); return true;
        case 1: pp->setDefaultOperation((SDN4CoRE::NetConfOperation_Operation)string2enum(value, "SDN4CoRE::NetConfOperation_Operation")); return true;
        case 2: pp->setErrorOption((SDN4CoRE::NetConfOperation_ErrorOption)string2enum(value, "SDN4CoRE::NetConfOperation_ErrorOption")); return true;
        default: return false;
    }
}

const char *NetConfOperation_EditConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NetConfOperation_EditConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_EditConfig *pp = (NetConfOperation_EditConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

NetConfConfig_Base::NetConfConfig_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->operation = 0;
}

NetConfConfig_Base::NetConfConfig_Base(const NetConfConfig_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

NetConfConfig_Base::~NetConfConfig_Base()
{
}

NetConfConfig_Base& NetConfConfig_Base::operator=(const NetConfConfig_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void NetConfConfig_Base::copy(const NetConfConfig_Base& other)
{
    this->operation = other.operation;
}

void NetConfConfig_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->operation);
}

void NetConfConfig_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->operation);
}

int NetConfConfig_Base::getOperation() const
{
    return this->operation;
}

void NetConfConfig_Base::setOperation(int operation)
{
    this->operation = operation;
}

class NetConfConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfConfigDescriptor();
    virtual ~NetConfConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfConfigDescriptor)

NetConfConfigDescriptor::NetConfConfigDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfConfig", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

NetConfConfigDescriptor::~NetConfConfigDescriptor()
{
    delete[] propertynames;
}

bool NetConfConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfConfig_Base *>(obj)!=nullptr;
}

const char **NetConfConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfConfigDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *NetConfConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "operation",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "operation")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *NetConfConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "SDN4CoRE::NetConfOperation_Operation";
            return nullptr;
        default: return nullptr;
    }
}

int NetConfConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfConfig_Base *pp = (NetConfConfig_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfConfig_Base *pp = (NetConfConfig_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfConfig_Base *pp = (NetConfConfig_Base *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getOperation(), "SDN4CoRE::NetConfOperation_Operation");
        default: return "";
    }
}

bool NetConfConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfConfig_Base *pp = (NetConfConfig_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setOperation((SDN4CoRE::NetConfOperation_Operation)string2enum(value, "SDN4CoRE::NetConfOperation_Operation")); return true;
        default: return false;
    }
}

const char *NetConfConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NetConfConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfConfig_Base *pp = (NetConfConfig_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_CopyConfig)

NetConfOperation_CopyConfig::NetConfOperation_CopyConfig(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(67);

}

NetConfOperation_CopyConfig::NetConfOperation_CopyConfig(const NetConfOperation_CopyConfig& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_CopyConfig::~NetConfOperation_CopyConfig()
{
}

NetConfOperation_CopyConfig& NetConfOperation_CopyConfig::operator=(const NetConfOperation_CopyConfig& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_CopyConfig::copy(const NetConfOperation_CopyConfig& other)
{
    this->source = other.source;
    this->target = other.target;
}

void NetConfOperation_CopyConfig::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->source);
    doParsimPacking(b,this->target);
}

void NetConfOperation_CopyConfig::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->source);
    doParsimUnpacking(b,this->target);
}

const char * NetConfOperation_CopyConfig::getSource() const
{
    return this->source.c_str();
}

void NetConfOperation_CopyConfig::setSource(const char * source)
{
    this->source = source;
}

const char * NetConfOperation_CopyConfig::getTarget() const
{
    return this->target.c_str();
}

void NetConfOperation_CopyConfig::setTarget(const char * target)
{
    this->target = target;
}

class NetConfOperation_CopyConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_CopyConfigDescriptor();
    virtual ~NetConfOperation_CopyConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_CopyConfigDescriptor)

NetConfOperation_CopyConfigDescriptor::NetConfOperation_CopyConfigDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_CopyConfig", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_CopyConfigDescriptor::~NetConfOperation_CopyConfigDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_CopyConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_CopyConfig *>(obj)!=nullptr;
}

const char **NetConfOperation_CopyConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_CopyConfigDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_CopyConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int NetConfOperation_CopyConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_CopyConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "source",
        "target",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int NetConfOperation_CopyConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "target")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_CopyConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_CopyConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_CopyConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_CopyConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CopyConfig *pp = (NetConfOperation_CopyConfig *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_CopyConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CopyConfig *pp = (NetConfOperation_CopyConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_CopyConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CopyConfig *pp = (NetConfOperation_CopyConfig *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSource());
        case 1: return oppstring2string(pp->getTarget());
        default: return "";
    }
}

bool NetConfOperation_CopyConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CopyConfig *pp = (NetConfOperation_CopyConfig *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource((value)); return true;
        case 1: pp->setTarget((value)); return true;
        default: return false;
    }
}

const char *NetConfOperation_CopyConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NetConfOperation_CopyConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CopyConfig *pp = (NetConfOperation_CopyConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_DeleteConfig)

NetConfOperation_DeleteConfig::NetConfOperation_DeleteConfig(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(51);

}

NetConfOperation_DeleteConfig::NetConfOperation_DeleteConfig(const NetConfOperation_DeleteConfig& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_DeleteConfig::~NetConfOperation_DeleteConfig()
{
}

NetConfOperation_DeleteConfig& NetConfOperation_DeleteConfig::operator=(const NetConfOperation_DeleteConfig& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_DeleteConfig::copy(const NetConfOperation_DeleteConfig& other)
{
    this->target = other.target;
}

void NetConfOperation_DeleteConfig::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->target);
}

void NetConfOperation_DeleteConfig::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->target);
}

const char * NetConfOperation_DeleteConfig::getTarget() const
{
    return this->target.c_str();
}

void NetConfOperation_DeleteConfig::setTarget(const char * target)
{
    this->target = target;
}

class NetConfOperation_DeleteConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_DeleteConfigDescriptor();
    virtual ~NetConfOperation_DeleteConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_DeleteConfigDescriptor)

NetConfOperation_DeleteConfigDescriptor::NetConfOperation_DeleteConfigDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_DeleteConfig", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_DeleteConfigDescriptor::~NetConfOperation_DeleteConfigDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_DeleteConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_DeleteConfig *>(obj)!=nullptr;
}

const char **NetConfOperation_DeleteConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_DeleteConfigDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_DeleteConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfOperation_DeleteConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_DeleteConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "target",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfOperation_DeleteConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "target")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_DeleteConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_DeleteConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_DeleteConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_DeleteConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_DeleteConfig *pp = (NetConfOperation_DeleteConfig *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_DeleteConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_DeleteConfig *pp = (NetConfOperation_DeleteConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_DeleteConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_DeleteConfig *pp = (NetConfOperation_DeleteConfig *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getTarget());
        default: return "";
    }
}

bool NetConfOperation_DeleteConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_DeleteConfig *pp = (NetConfOperation_DeleteConfig *)object; (void)pp;
    switch (field) {
        case 0: pp->setTarget((value)); return true;
        default: return false;
    }
}

const char *NetConfOperation_DeleteConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NetConfOperation_DeleteConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_DeleteConfig *pp = (NetConfOperation_DeleteConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_Get)

NetConfOperation_Get::NetConfOperation_Get(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(99);

}

NetConfOperation_Get::NetConfOperation_Get(const NetConfOperation_Get& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_Get::~NetConfOperation_Get()
{
}

NetConfOperation_Get& NetConfOperation_Get::operator=(const NetConfOperation_Get& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_Get::copy(const NetConfOperation_Get& other)
{
    this->filter = other.filter;
}

void NetConfOperation_Get::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->filter);
}

void NetConfOperation_Get::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->filter);
}

NetConfFilter& NetConfOperation_Get::getFilter()
{
    return this->filter;
}

void NetConfOperation_Get::setFilter(const NetConfFilter& filter)
{
    this->filter = filter;
}

class NetConfOperation_GetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_GetDescriptor();
    virtual ~NetConfOperation_GetDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_GetDescriptor)

NetConfOperation_GetDescriptor::NetConfOperation_GetDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_Get", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_GetDescriptor::~NetConfOperation_GetDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_GetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_Get *>(obj)!=nullptr;
}

const char **NetConfOperation_GetDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_GetDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_GetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfOperation_GetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_GetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "filter",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfOperation_GetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "filter")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_GetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "NetConfFilter",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_GetDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_GetDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_GetDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Get *pp = (NetConfOperation_Get *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_GetDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Get *pp = (NetConfOperation_Get *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_GetDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Get *pp = (NetConfOperation_Get *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getFilter(); return out.str();}
        default: return "";
    }
}

bool NetConfOperation_GetDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Get *pp = (NetConfOperation_Get *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConfOperation_GetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(NetConfFilter));
        default: return nullptr;
    };
}

void *NetConfOperation_GetDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Get *pp = (NetConfOperation_Get *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getFilter()); break;
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_CloseSession)

NetConfOperation_CloseSession::NetConfOperation_CloseSession(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(16);
}

NetConfOperation_CloseSession::NetConfOperation_CloseSession(const NetConfOperation_CloseSession& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_CloseSession::~NetConfOperation_CloseSession()
{
}

NetConfOperation_CloseSession& NetConfOperation_CloseSession::operator=(const NetConfOperation_CloseSession& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_CloseSession::copy(const NetConfOperation_CloseSession& other)
{
}

void NetConfOperation_CloseSession::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
}

void NetConfOperation_CloseSession::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
}

class NetConfOperation_CloseSessionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_CloseSessionDescriptor();
    virtual ~NetConfOperation_CloseSessionDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_CloseSessionDescriptor)

NetConfOperation_CloseSessionDescriptor::NetConfOperation_CloseSessionDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_CloseSession", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_CloseSessionDescriptor::~NetConfOperation_CloseSessionDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_CloseSessionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_CloseSession *>(obj)!=nullptr;
}

const char **NetConfOperation_CloseSessionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_CloseSessionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_CloseSessionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConfOperation_CloseSessionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConfOperation_CloseSessionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConfOperation_CloseSessionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_CloseSessionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConfOperation_CloseSessionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_CloseSessionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_CloseSessionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CloseSession *pp = (NetConfOperation_CloseSession *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_CloseSessionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CloseSession *pp = (NetConfOperation_CloseSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_CloseSessionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CloseSession *pp = (NetConfOperation_CloseSession *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConfOperation_CloseSessionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CloseSession *pp = (NetConfOperation_CloseSession *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConfOperation_CloseSessionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConfOperation_CloseSessionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_CloseSession *pp = (NetConfOperation_CloseSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_Lock)

NetConfOperation_Lock::NetConfOperation_Lock(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(33);

}

NetConfOperation_Lock::NetConfOperation_Lock(const NetConfOperation_Lock& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_Lock::~NetConfOperation_Lock()
{
}

NetConfOperation_Lock& NetConfOperation_Lock::operator=(const NetConfOperation_Lock& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_Lock::copy(const NetConfOperation_Lock& other)
{
    this->target = other.target;
}

void NetConfOperation_Lock::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->target);
}

void NetConfOperation_Lock::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->target);
}

const char * NetConfOperation_Lock::getTarget() const
{
    return this->target.c_str();
}

void NetConfOperation_Lock::setTarget(const char * target)
{
    this->target = target;
}

class NetConfOperation_LockDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_LockDescriptor();
    virtual ~NetConfOperation_LockDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_LockDescriptor)

NetConfOperation_LockDescriptor::NetConfOperation_LockDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_Lock", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_LockDescriptor::~NetConfOperation_LockDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_LockDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_Lock *>(obj)!=nullptr;
}

const char **NetConfOperation_LockDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_LockDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_LockDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfOperation_LockDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_LockDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "target",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfOperation_LockDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "target")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_LockDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_LockDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_LockDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_LockDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Lock *pp = (NetConfOperation_Lock *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_LockDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Lock *pp = (NetConfOperation_Lock *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_LockDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Lock *pp = (NetConfOperation_Lock *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getTarget());
        default: return "";
    }
}

bool NetConfOperation_LockDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Lock *pp = (NetConfOperation_Lock *)object; (void)pp;
    switch (field) {
        case 0: pp->setTarget((value)); return true;
        default: return false;
    }
}

const char *NetConfOperation_LockDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NetConfOperation_LockDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Lock *pp = (NetConfOperation_Lock *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_Unlock)

NetConfOperation_Unlock::NetConfOperation_Unlock(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(37);

}

NetConfOperation_Unlock::NetConfOperation_Unlock(const NetConfOperation_Unlock& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_Unlock::~NetConfOperation_Unlock()
{
}

NetConfOperation_Unlock& NetConfOperation_Unlock::operator=(const NetConfOperation_Unlock& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_Unlock::copy(const NetConfOperation_Unlock& other)
{
    this->target = other.target;
}

void NetConfOperation_Unlock::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
    doParsimPacking(b,this->target);
}

void NetConfOperation_Unlock::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
    doParsimUnpacking(b,this->target);
}

const char * NetConfOperation_Unlock::getTarget() const
{
    return this->target.c_str();
}

void NetConfOperation_Unlock::setTarget(const char * target)
{
    this->target = target;
}

class NetConfOperation_UnlockDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_UnlockDescriptor();
    virtual ~NetConfOperation_UnlockDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_UnlockDescriptor)

NetConfOperation_UnlockDescriptor::NetConfOperation_UnlockDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_Unlock", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_UnlockDescriptor::~NetConfOperation_UnlockDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_UnlockDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_Unlock *>(obj)!=nullptr;
}

const char **NetConfOperation_UnlockDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_UnlockDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_UnlockDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfOperation_UnlockDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *NetConfOperation_UnlockDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "target",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfOperation_UnlockDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "target")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_UnlockDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfOperation_UnlockDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_UnlockDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_UnlockDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Unlock *pp = (NetConfOperation_Unlock *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_UnlockDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Unlock *pp = (NetConfOperation_Unlock *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_UnlockDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Unlock *pp = (NetConfOperation_Unlock *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getTarget());
        default: return "";
    }
}

bool NetConfOperation_UnlockDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Unlock *pp = (NetConfOperation_Unlock *)object; (void)pp;
    switch (field) {
        case 0: pp->setTarget((value)); return true;
        default: return false;
    }
}

const char *NetConfOperation_UnlockDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NetConfOperation_UnlockDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Unlock *pp = (NetConfOperation_Unlock *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_Commit)

NetConfOperation_Commit::NetConfOperation_Commit(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(9);
}

NetConfOperation_Commit::NetConfOperation_Commit(const NetConfOperation_Commit& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_Commit::~NetConfOperation_Commit()
{
}

NetConfOperation_Commit& NetConfOperation_Commit::operator=(const NetConfOperation_Commit& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_Commit::copy(const NetConfOperation_Commit& other)
{
}

void NetConfOperation_Commit::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
}

void NetConfOperation_Commit::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
}

class NetConfOperation_CommitDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_CommitDescriptor();
    virtual ~NetConfOperation_CommitDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_CommitDescriptor)

NetConfOperation_CommitDescriptor::NetConfOperation_CommitDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_Commit", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_CommitDescriptor::~NetConfOperation_CommitDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_CommitDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_Commit *>(obj)!=nullptr;
}

const char **NetConfOperation_CommitDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_CommitDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_CommitDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConfOperation_CommitDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConfOperation_CommitDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConfOperation_CommitDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_CommitDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConfOperation_CommitDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_CommitDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_CommitDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Commit *pp = (NetConfOperation_Commit *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_CommitDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Commit *pp = (NetConfOperation_Commit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_CommitDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Commit *pp = (NetConfOperation_Commit *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConfOperation_CommitDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Commit *pp = (NetConfOperation_Commit *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConfOperation_CommitDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConfOperation_CommitDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Commit *pp = (NetConfOperation_Commit *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfOperation_Discard_Changes)

NetConfOperation_Discard_Changes::NetConfOperation_Discard_Changes(const char *name, short kind) : ::SDN4CoRE::NetConfOperation(name,kind)
{
    this->setByteLength(18);
}

NetConfOperation_Discard_Changes::NetConfOperation_Discard_Changes(const NetConfOperation_Discard_Changes& other) : ::SDN4CoRE::NetConfOperation(other)
{
    copy(other);
}

NetConfOperation_Discard_Changes::~NetConfOperation_Discard_Changes()
{
}

NetConfOperation_Discard_Changes& NetConfOperation_Discard_Changes::operator=(const NetConfOperation_Discard_Changes& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfOperation::operator=(other);
    copy(other);
    return *this;
}

void NetConfOperation_Discard_Changes::copy(const NetConfOperation_Discard_Changes& other)
{
}

void NetConfOperation_Discard_Changes::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfOperation::parsimPack(b);
}

void NetConfOperation_Discard_Changes::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfOperation::parsimUnpack(b);
}

class NetConfOperation_Discard_ChangesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfOperation_Discard_ChangesDescriptor();
    virtual ~NetConfOperation_Discard_ChangesDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NetConfOperation_Discard_ChangesDescriptor)

NetConfOperation_Discard_ChangesDescriptor::NetConfOperation_Discard_ChangesDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfOperation_Discard_Changes", "SDN4CoRE::NetConfOperation")
{
    propertynames = nullptr;
}

NetConfOperation_Discard_ChangesDescriptor::~NetConfOperation_Discard_ChangesDescriptor()
{
    delete[] propertynames;
}

bool NetConfOperation_Discard_ChangesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfOperation_Discard_Changes *>(obj)!=nullptr;
}

const char **NetConfOperation_Discard_ChangesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfOperation_Discard_ChangesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfOperation_Discard_ChangesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConfOperation_Discard_ChangesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConfOperation_Discard_ChangesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConfOperation_Discard_ChangesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfOperation_Discard_ChangesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConfOperation_Discard_ChangesDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NetConfOperation_Discard_ChangesDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NetConfOperation_Discard_ChangesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Discard_Changes *pp = (NetConfOperation_Discard_Changes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfOperation_Discard_ChangesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Discard_Changes *pp = (NetConfOperation_Discard_Changes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfOperation_Discard_ChangesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Discard_Changes *pp = (NetConfOperation_Discard_Changes *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConfOperation_Discard_ChangesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Discard_Changes *pp = (NetConfOperation_Discard_Changes *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConfOperation_Discard_ChangesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConfOperation_Discard_ChangesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfOperation_Discard_Changes *pp = (NetConfOperation_Discard_Changes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace SDN4CoRE

