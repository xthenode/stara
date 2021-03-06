%########################################################################
%# Copyright (c) 1988-2020 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: xttp-message-part-hxx.t
%#
%# Author: $author$
%#   Date: 6/14/2020
%########################################################################
%with(%
%is_include_path,%(%else-then(%is_include_path%,%(%is_Include_path%)%)%)%,%
%include_path,%(%else-then(%if-no(%is_include_path%,,%(%include_path%)%)%,%(%if-no(%is_include_path%,,%(%filepath(%input%)%)%)%)%)%)%,%
%Include_path,%(%else-then(%if-no(%is_include_path%,,%(%Include_path%)%)%,%(%if-no(%is_include_path%,,%(%include_path%)%)%)%)%)%,%
%INCLUDE_PATH,%(%else-then(%INCLUDE_PATH%,%(%toupper(%Include_path%)%)%)%)%,%
%include_path,%(%else-then(%_include_path%,%(%tolower(%Include_path%)%)%)%)%,%
%is_framework,%(%else-then(%is_framework%,%(%is_Framework%)%)%)%,%
%framework,%(%else-then(%if-no(%is_framework%,,%(%framework%)%)%,%(%if-no(%is_framework%,,%(xos)%)%)%)%)%,%
%Framework,%(%else-then(%if-no(%is_framework%,,%(%Framework%)%)%,%(%if-no(%is_framework%,,%(%framework%)%)%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_framework%,%(%tolower(%Framework%)%)%)%)%,%
%is_section,%(%else-then(%is_section%,%(%is_Section%)%)%)%,%
%section,%(%else-then(%if-no(%is_section%,,%(%section%)%)%,%(%if-no(%is_section%,,%(internet)%)%)%)%)%,%
%Section,%(%else-then(%if-no(%is_section%,,%(%Section%)%)%,%(%if-no(%is_section%,,%(%section%)%)%)%)%)%,%
%SECTION,%(%else-then(%SECTION%,%(%toupper(%Section%)%)%)%)%,%
%section,%(%else-then(%_section%,%(%tolower(%Section%)%)%)%)%,%
%is_namespace,%(%else-then(%is_namespace%,%(%is_Namespace%)%)%)%,%
%namespace,%(%else-then(%if-no(%is_namespace%,,%(%namespace%)%)%,%(%if-no(%is_namespace%,,%(protocol)%)%)%)%)%,%
%Namespace,%(%else-then(%if-no(%is_namespace%,,%(%Namespace%)%)%,%(%if-no(%is_namespace%,,%(%namespace%)%)%)%)%)%,%
%NAMESPACE,%(%else-then(%NAMESPACE%,%(%toupper(%Namespace%)%)%)%)%,%
%namespace,%(%else-then(%_namespace%,%(%tolower(%Namespace%)%)%)%)%,%
%is_protocol,%(%else-then(%is_protocol%,%(%is_Protocol%)%)%)%,%
%protocol,%(%else-then(%if-no(%is_protocol%,,%(%protocol%)%)%,%(%if-no(%is_protocol%,,%(xttp)%)%)%)%)%,%
%Protocol,%(%else-then(%if-no(%is_protocol%,,%(%Protocol%)%)%,%(%if-no(%is_protocol%,,%(%protocol%)%)%)%)%)%,%
%PROTOCOL,%(%else-then(%PROTOCOL%,%(%toupper(%Protocol%)%)%)%)%,%
%protocol,%(%else-then(%_protocol%,%(%tolower(%Protocol%)%)%)%)%,%
%is_message,%(%else-then(%is_message%,%(%is_Message%)%)%)%,%
%message,%(%else-then(%if-no(%is_message%,,%(%message%)%)%,%(%if-no(%is_message%,,%(message)%)%)%)%)%,%
%Message,%(%else-then(%if-no(%is_message%,,%(%Message%)%)%,%(%if-no(%is_message%,,%(%message%)%)%)%)%)%,%
%MESSAGE,%(%else-then(%MESSAGE%,%(%toupper(%Message%)%)%)%)%,%
%message,%(%else-then(%_message%,%(%tolower(%Message%)%)%)%)%,%
%is_extends_message,%(%else-then(%is_extends_message%,%(%is_Extends_message%)%)%)%,%
%extends_message,%(%else-then(%if-no(%is_extends_message%,,%(%extends_message%)%)%,%(%if-no(%is_extends_message%,,%(%Message%)%)%)%)%)%,%
%Extends_message,%(%else-then(%if-no(%is_extends_message%,,%(%Extends_message%)%)%,%(%if-no(%is_extends_message%,,%(%extends_message%)%)%)%)%)%,%
%EXTENDS_MESSAGE,%(%else-then(%EXTENDS_MESSAGE%,%(%toupper(%Extends_message%)%)%)%)%,%
%extends_message,%(%else-then(%_extends_message%,%(%tolower(%Extends_message%)%)%)%)%,%
%is_path,%(%else-then(%is_path%,%(%is_Path%)%)%)%,%
%path,%(%else-then(%if-no(%is_path%,,%(%path%)%)%,%(%if-no(%is_path%,,%(%if-then(%Section%,/)%%Namespace%%then-if(%Protocol%,/)%%then-if(%Message%,/)%)%)%)%)%)%,%
%Path,%(%else-then(%if-no(%is_path%,,%(%Path%)%)%,%(%if-no(%is_path%,,%(%path%)%)%)%)%)%,%
%PATH,%(%else-then(%PATH%,%(%toupper(%Path%)%)%)%)%,%
%path,%(%else-then(%_path%,%(%tolower(%Path%)%)%)%)%,%
%is_path_of_extends,%(%else-then(%is_path_of_extends%,%(%is_Path_of_extends%)%)%)%,%
%path_of_extends,%(%else-then(%if-no(%is_path_of_extends%,,%(%path_of_extends%)%)%,%(%if-no(%is_path_of_extends%,,%(%if-then(%Section%,/)%%Namespace%%then-if(%Protocol%,/)%%then-if(%Extends_message%,/)%)%)%)%)%)%,%
%Path_of_extends,%(%else-then(%if-no(%is_path_of_extends%,,%(%Path_of_extends%)%)%,%(%if-no(%is_path_of_extends%,,%(%path_of_extends%)%)%)%)%)%,%
%PATH_OF_EXTENDS,%(%else-then(%PATH_OF_EXTENDS%,%(%toupper(%Path_of_extends%)%)%)%)%,%
%path_of_extends,%(%else-then(%_path_of_extends%,%(%tolower(%Path_of_extends%)%)%)%)%,%
%is_extends_path,%(%else-then(%is_extends_path%,%(%is_Extends_path%)%)%)%,%
%extends_path,%(%else-then(%if-no(%is_extends_path%,,%(%extends_path%)%)%,%(%if-no(%is_extends_path%,,%(%Framework%/%Path%)%)%)%)%)%,%
%Extends_path,%(%else-then(%if-no(%is_extends_path%,,%(%Extends_path%)%)%,%(%if-no(%is_extends_path%,,%(%extends_path%)%)%)%)%)%,%
%EXTENDS_PATH,%(%else-then(%EXTENDS_PATH%,%(%toupper(%Extends_path%)%)%)%)%,%
%extends_path,%(%else-then(%_extends_path%,%(%tolower(%Extends_path%)%)%)%)%,%
%is_extends,%(%else-then(%is_extends%,%(%is_Extends%)%)%)%,%
%extends,%(%else-then(%if-no(%is_extends%,,%(%extends%)%)%,%(%if-no(%is_extends%,,%(part)%)%)%)%)%,%
%Extends,%(%else-then(%if-no(%is_extends%,,%(%Extends%)%)%,%(%if-no(%is_extends%,,%(%extends%)%)%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_extends%,%(%tolower(%Extends%)%)%)%)%,%
%is_extends_ns,%(%else-then(%is_extends_ns%,%(%is_Extends_ns%)%)%)%,%
%extends_ns,%(%else-then(%if-no(%is_extends_ns%,,%(%extends_ns%)%)%,%(%if-no(%is_extends_ns%,,%(%parse(%Path_of_extends%/%Extends%,/,,%(::)%)%)%)%)%)%)%,%
%Extends_ns,%(%else-then(%if-no(%is_extends_ns%,,%(%Extends_ns%)%)%,%(%if-no(%is_extends_ns%,,%(%extends_ns%)%)%)%)%)%,%
%EXTENDS_NS,%(%else-then(%EXTENDS_NS%,%(%toupper(%Extends_ns%)%)%)%)%,%
%extends_ns,%(%else-then(%_extends_ns%,%(%tolower(%Extends_ns%)%)%)%)%,%
%is_extends_include_path,%(%else-then(%is_extends_include_path%,%(%is_Extends_include_path%)%)%)%,%
%extends_include_path,%(%else-then(%if-no(%is_extends_include_path%,,%(%extends_include_path%)%)%,%(%if-no(%is_extends_include_path%,,%(%Framework%/%Path_of_extends%/%Extends%)%)%)%)%)%,%
%Extends_include_path,%(%else-then(%if-no(%is_extends_include_path%,,%(%Extends_include_path%)%)%,%(%if-no(%is_extends_include_path%,,%(%extends_include_path%)%)%)%)%)%,%
%EXTENDS_INCLUDE_PATH,%(%else-then(%EXTENDS_INCLUDE_PATH%,%(%toupper(%Extends_include_path%)%)%)%)%,%
%extends_include_path,%(%else-then(%_extends_include_path%,%(%tolower(%Extends_include_path%)%)%)%)%,%
%is_what,%(%else-then(%is_what%,%(%is_What%)%)%)%,%
%what,%(%else-then(%if-no(%is_what%,,%(%what%)%)%,%(%if-no(%is_what%,,%(what)%)%)%)%)%,%
%What,%(%else-then(%if-no(%is_what%,,%(%What%)%)%,%(%if-no(%is_what%,,%(%what%)%)%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_what%,%(%tolower(%What%)%)%)%)%,%
%is_part,%(%else-then(%is_part%,%(%is_Part%)%)%)%,%
%part,%(%else-then(%if-no(%is_part%,,%(%part%)%)%,%(%if-no(%is_part%,,%(%What%)%)%)%)%)%,%
%Part,%(%else-then(%if-no(%is_part%,,%(%Part%)%)%,%(%if-no(%is_part%,,%(%part%)%)%)%)%)%,%
%PART,%(%else-then(%PART%,%(%toupper(%Part%)%)%)%)%,%
%part,%(%else-then(%_part%,%(%tolower(%Part%)%)%)%)%,%
%is_name,%(%else-then(%is_name%,%(%is_Name%)%)%)%,%
%name,%(%else-then(%if-no(%is_name%,,%(%name%)%)%,%(%if-no(%is_name%,,%(%Part%)%)%)%)%)%,%
%Name,%(%else-then(%if-no(%is_name%,,%(%Name%)%)%,%(%if-no(%is_name%,,%(%name%)%)%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_name%,%(%tolower(%Name%)%)%)%)%,%
%is_filetypeextension,%(%else-then(%is_filetypeextension%,%(%is_FileTypeExtension%)%)%)%,%
%filetypeextension,%(%else-then(%if-no(%is_filetypeextension%,,%(%filetypeextension%)%)%,%(%if-no(%is_filetypeextension%,,%(hpp)%)%)%)%)%,%
%FileTypeExtension,%(%else-then(%if-no(%is_filetypeextension%,,%(%FileTypeExtension%)%)%,%(%if-no(%is_filetypeextension%,,%(%filetypeextension%)%)%)%)%)%,%
%FILETYPEEXTENSION,%(%else-then(%FILETYPEEXTENSION%,%(%toupper(%FileTypeExtension%)%)%)%)%,%
%filetypeextension,%(%else-then(%_filetypeextension%,%(%tolower(%FileTypeExtension%)%)%)%)%,%
%is_extension,%(%else-then(%is_extension%,%(%is_Extension%)%)%)%,%
%extension,%(%else-then(%if-no(%is_extension%,,%(%extension%)%)%,%(%if-no(%is_extension%,,%(%else-then(%fileextension(%File%)%,%(%FileTypeExtension%)%)%)%)%)%)%)%,%
%Extension,%(%else-then(%if-no(%is_extension%,,%(%Extension%)%)%,%(%if-no(%is_extension%,,%(%extension%)%)%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_extension%,%(%tolower(%Extension%)%)%)%)%,%
%is_ifndef,%(%else-then(%is_ifndef%,%(%is_Ifndef%)%)%)%,%
%ifndef,%(%else-then(%if-no(%is_ifndef%,,%(%ifndef%)%)%,%(%if-no(%is_ifndef%,,%(%FRAMEWORK%_%parse(%PATH%,/,,_)%_%NAME%_%EXTENSION%)%)%)%)%)%,%
%Ifndef,%(%else-then(%if-no(%is_ifndef%,,%(%Ifndef%)%)%,%(%if-no(%is_ifndef%,,%(%ifndef%)%)%)%)%)%,%
%IFNDEF,%(%else-then(%IFNDEF%,%(%toupper(%Ifndef%)%)%)%)%,%
%ifndef,%(%else-then(%_ifndef%,%(%tolower(%Ifndef%)%)%)%)%,%
%is_extends_include,%(%else-then(%is_extends_include%,%(%is_Extends_include%)%)%)%,%
%extends_include,%(%else-then(%if-no(%is_extends_include%,,%(%extends_include%)%)%,%(%if-no(%is_extends_include%,,%(%Extends_include_path%%then-if(%Extension%,.)%)%)%)%)%)%,%
%Extends_include,%(%else-then(%if-no(%is_extends_include%,,%(%Extends_include%)%)%,%(%if-no(%is_extends_include%,,%(%extends_include%)%)%)%)%)%,%
%EXTENDS_INCLUDE,%(%else-then(%EXTENDS_INCLUDE%,%(%toupper(%Extends_include%)%)%)%)%,%
%extends_include,%(%else-then(%_extends_include%,%(%tolower(%Extends_include%)%)%)%)%,%
%is_namespace_begin,%(%else-then(%is_namespace_begin%,%(%is_Namespace_begin%)%)%)%,%
%namespace_begin,%(%else-then(%if-no(%is_namespace_begin%,,%(%namespace_begin%)%)%,%(%if-no(%is_namespace_begin%,,%(%
%%if-then(%parse(%left-of-right(%Framework%/%Path%/%Extends%,/)%,/,,,,%(namespace %ns% {
)%,ns)%,%(
)%)%%
%)%)%)%)%)%,%
%Namespace_begin,%(%else-then(%if-no(%is_namespace_begin%,,%(%Namespace_begin%)%)%,%(%if-no(%is_namespace_begin%,,%(%namespace_begin%)%)%)%)%)%,%
%NAMESPACE_BEGIN,%(%else-then(%NAMESPACE_BEGIN%,%(%toupper(%Namespace_begin%)%)%)%)%,%
%namespace_begin,%(%else-then(%_namespace_begin%,%(%tolower(%Namespace_begin%)%)%)%)%,%
%is_namespace_end,%(%else-then(%is_namespace_end%,%(%is_Namespace_end%)%)%)%,%
%namespace_end,%(%else-then(%if-no(%is_namespace_end%,,%(%namespace_end%)%)%,%(%if-no(%is_namespace_end%,,%(%then-if(%
%%reverse-parse(%left-of-right(%Framework%/%Path%/%Extends%,/)%,/,,,,%(
} /// namespace %ns%)%,ns)%,%(
)%)%)%)%)%)%)%,%
%Namespace_end,%(%else-then(%if-no(%is_namespace_end%,,%(%Namespace_end%)%)%,%(%if-no(%is_namespace_end%,,%(%namespace_end%)%)%)%)%)%,%
%NAMESPACE_END,%(%else-then(%NAMESPACE_END%,%(%toupper(%Namespace_end%)%)%)%)%,%
%namespace_end,%(%else-then(%_namespace_end%,%(%tolower(%Namespace_end%)%)%)%)%,%
%%(%
%%include(%Include_path%/hxx-cxx-file.t)%%
%#ifndef %IFNDEF%
#define %IFNDEF%

#include "%Extends_include%"

%Namespace_begin%/// class %Part%t
template <class TExtends = %Extends_ns%, class TImplements = typename TExtends::implements>
class exported %Part%t: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef %Part%t derives;
    
    typedef typename extends::char_t char_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::sstream_t sstream_t;
    typedef typename extends::sequence_t sequence_t;
    typedef typename extends::seeker_t seeker_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef extends part_t;

    /// constructor / destructor
    %Part%t(const string_t& chars): extends(chars) {
        this->separate();
    }
    %Part%t(const char_t* chars, size_t length): extends(chars, length) {
        this->separate();
    }
    %Part%t(const char_t* chars): extends(chars) {
        this->separate();
    }
    %Part%t(const part_t& copy): extends(copy) {
    }
    %Part%t(const derives& copy): extends(copy) {
    }
    %Part%t() {
        this->set_default();
    }
    virtual ~%Part%t() {
    }

    /// read / write
    virtual bool read(ssize_t& count, char_t& c, reader_t& reader) {
        bool success = false;
        // success = this->read_this(count, c, reader);
        return success;
    }
    virtual bool write(ssize_t& count, writer_t& writer) {
        bool success = false;
        // success = this->write_this(count, writer);
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

protected:
}; /// class %Part%t
typedef %Part%t<> %Part%;%Namespace_end%

#endif ///ndef %IFNDEF%
)%)%