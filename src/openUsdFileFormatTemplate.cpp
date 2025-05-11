#include "openUsdFileFormatTemplate.h"
#include "debugCodes.h"

#include <pxr/usd/sdf/api.h>
#include <pxr/usd/sdf/abstractData.h>
#include <pxr/usd/sdf/fileFormat.h>
#include <pxr/base/tf/declarePtrs.h>
#include <pxr/base/tf/token.h>
#include <pxr/base/vt/value.h>
#include <pxr/usd/pcp/dynamicFileFormatInterface.h>
#include <pxr/base/tf/staticTokens.h>
#include <pxr/base/tf/pathUtils.h>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) 
{
    SDF_DEFINE_FILE_FORMAT(OpenUsdFileFormatTemplateFileFormat, SdfFileFormat);
}

// Define the tokens
TF_DEFINE_PUBLIC_TOKENS(OpenUsdFileFormatTemplateFileFormatTokens, OPENUSDFILEFORMATTEMPLATE_FILE_FORMAT_TOKENS);

OpenUsdFileFormatTemplateFileFormat::OpenUsdFileFormatTemplateFileFormat()
    : SdfFileFormat(
        OpenUsdFileFormatTemplateFileFormatTokens->Id,
        OpenUsdFileFormatTemplateFileFormatTokens->Version,
        OpenUsdFileFormatTemplateFileFormatTokens->Target,
        OpenUsdFileFormatTemplateFileFormatTokens->Extension)
{
}

OpenUsdFileFormatTemplateFileFormat::~OpenUsdFileFormatTemplateFileFormat()
{
}

bool OpenUsdFileFormatTemplateFileFormat::CanRead(const std::string& file) const
{
    TF_DEBUG( OPENUSDFILEFORMATTEMPLATE ).Msg( "CanRead %s\n", file.c_str() );

	const auto extension = TfGetExtension( file );

	if( extension.empty() )
	{
		TF_DEBUG( OPENUSDFILEFORMATTEMPLATE ).Msg( "No File extension found! Unable to read \"%s\"", file.c_str() );
		return false;
	}

	return extension == GetFormatId();
}

bool OpenUsdFileFormatTemplateFileFormat::Read(SdfLayer* layer, const std::string& file, bool metadataOnly) const
{
    TF_DEBUG( OPENUSDFILEFORMATTEMPLATE ).Msg( "Read %s\n", file.c_str() );

    if (!TF_VERIFY(layer)) {
        return false;
    }
    
    // Implement File Reading
    return true;
}

PXR_NAMESPACE_CLOSE_SCOPE