#include "CoreGlobals.h"
#include "Misc/App.h"
#include "Misc/CommandLine.h"
#include "Misc/ConfigCacheIni.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogPSOCacheBuster, Display, All);

class FPSOCacheBusterModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
#if IS_CLIENT_TARGET || UE_GAME // Ignore Editor, Server, and Program build targets

		if (FApp::GetBuildConfiguration() == EBuildConfiguration::Shipping)
		{
			bool bRunInShippingBuilds = false;
			GConfig->GetBool(TEXT("PSOCacheBuster"), TEXT("bRunInShippingBuilds"), bRunInShippingBuilds, GGameIni);
			if (!bRunInShippingBuilds)
			{
				// Do not run in Shipping configuration (unless configured to)
				return;
			}
		}

		if (FParse::Param(FCommandLine::Get(), TEXT("clearPSODriverCache")))
		{
			// PSO Driver Cache is already set to be cleared
			return;
		}

		// Append -clearPSODriverCache to the command line.
		UE_LOG(LogPSOCacheBuster, Log, TEXT("Busting the PSO cache."));
		FCommandLine::Append(TEXT(" -clearPSODriverCache"));
#endif
	}
};

IMPLEMENT_MODULE(FPSOCacheBusterModule, PSOCacheBuster)
