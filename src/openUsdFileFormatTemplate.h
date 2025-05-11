#include <pxr/pxr.h>
#include <pxr/usd/sdf/api.h>
#include <pxr/usd/sdf/abstractData.h>
#include <pxr/usd/sdf/fileFormat.h>
#include <pxr/base/tf/declarePtrs.h>
#include <pxr/base/tf/token.h>
#include <pxr/base/vt/value.h>
#include <pxr/usd/pcp/dynamicFileFormatInterface.h>
#include <pxr/base/tf/staticTokens.h>

PXR_NAMESPACE_USING_DIRECTIVE

PXR_NAMESPACE_OPEN_SCOPE

#define OPENUSDFILEFORMATTEMPLATE_FILE_FORMAT_TOKENS \
    ((Id, "OpenUsdFileFormatTemplate")) \
    ((Version, "1.0")) \
    ((Target, "usd")) \
    ((Extension, "OpenUsdFileFormatTemplate"))


TF_DECLARE_PUBLIC_TOKENS(OpenUsdFileFormatTemplateFileFormatTokens, OPENUSDFILEFORMATTEMPLATE_FILE_FORMAT_TOKENS);

TF_DECLARE_WEAK_AND_REF_PTRS(OpenUsdFileFormatTemplateFileFormat);

class OpenUsdFileFormatTemplateFileFormat : public SdfFileFormat
{
public:
    virtual bool CanRead(const std::string &file) const override;

    virtual bool Read(SdfLayer *layer, const std::string &file, bool metadataOnly) const override;

    // Other I/O functions
    /*
    virtual TfRefPtr<SdfAbstractData> InitData(const std::map<std::string, std::string>& args) const override;

    virtual bool WriteToFile(const SdfLayer &layer, const std::string &file, const std::string &comment = std::string()) const override;

    virtual bool ReadFromString(SdfLayer *layer, const std::string &input) const override;

    virtual bool WriteToStream(const SdfSpecHandle &spec,
                               std::ostream &out,
                               size_t indent) const override;

    virtual bool WriteToString(const SdfLayer &layer,
                               std::string *str,
                               const std::string &comment = std::string()) const override;

    virtual bool ReadFromStream(SdfLayer* layer,
                        std::istream& input,
                        bool metadataOnly,
                        std::string* outError,
                        std::istream& mtlinput) const;
    */

protected:
    SDF_FILE_FORMAT_FACTORY_ACCESS;

    virtual ~OpenUsdFileFormatTemplateFileFormat();
    OpenUsdFileFormatTemplateFileFormat();
};

PXR_NAMESPACE_CLOSE_SCOPE
