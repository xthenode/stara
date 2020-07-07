///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: string.hpp
///
/// Author: $author$
///   Date: 7/7/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_CONTENT_JSON_STRING_HPP
#define XOS_PROTOCOL_XTTP_CONTENT_JSON_STRING_HPP

#include "xos/protocol/xttp/content/json/node_type.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace content {
namespace json {

/// class stringt
template <class TExtends = message::part, class TImplements = typename TExtends::implements>
class exported stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef stringt derives;

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    stringt(const string_t& chars): extends(chars) {
        this->separate();
    }
    stringt(const char_t* chars, size_t length): extends(chars, length) {
        this->separate();
    }
    stringt(const char_t* chars): extends(chars) {
        this->separate();
    }
    stringt(const stringt& copy): extends(copy) {
    }
    stringt() {
        this->set_default();
    }
    virtual ~stringt() {
    }

    /// read / write
    virtual bool read(ssize_t& count, char_t& c, reader_t& reader) {
        bool success = false;
        // success = this->read_this(count, c, reader);
        return success;
    }
    virtual bool write(ssize_t& count, writer_t& writer) {
        bool success = this->write_this(count, writer);
        return success;
    }

    /// combine / separate
    virtual bool combine() {
        bool success = true;
        return success;
    }
    virtual bool separate() {
        bool success = true;
        return success;
    }

    /// set_default...
    virtual derives& set_default() {
        this->clear();
        set_defaults();
        return *this;
    }
    virtual derives& set_defaults() {
        return *this;
    }

    /// ...to
    virtual string_t& assign_to(string_t& to) const {
        to.clear();
        append_to(to);
        return to;
    }
    virtual string_t& append_to(string_t& to) const {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = this->has_chars(length))) {
            to.append(chars, length);
        }
        return to;
    }
    virtual string_t& assign_literal_to(string_t& to) const {
        to.clear();
        append_literal_to(to);
        return to;
    }
    virtual string_t& append_literal_to(string_t& to) const {
        const char_t* chars = 0; size_t length = 0;
        to.append("\"");
        if ((chars = this->has_chars(length))) {
            for (char c = 0; (0 < length); ++chars, --length) {
                switch (c = ((char)(*chars))) {
                case '"':
                    to.append("\\", 1);
                default:
                    to.append(chars, 1);
                    break;
                }
            }
        }
        to.append("\"");
        return to;
    }
}; /// class stringt
typedef stringt<> string;

} /// namespace json
} /// namespace content
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_CONTENT_JSON_STRING_HPP 
