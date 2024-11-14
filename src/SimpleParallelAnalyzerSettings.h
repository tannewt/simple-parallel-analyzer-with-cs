#ifndef SIMPLEPARALLEL_ANALYZER_SETTINGS
#define SIMPLEPARALLEL_ANALYZER_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

// originally from AnalyzerEnums::EdgeDirection { PosEdge, NegEdge };
enum class ParallelAnalyzerClockEdge
{
    PosEdge = AnalyzerEnums::PosEdge,
    NegEdge = AnalyzerEnums::NegEdge,
    DualEdge
};

class SimpleParallelAnalyzerSettings : public AnalyzerSettings
{
  public:
    SimpleParallelAnalyzerSettings();
    virtual ~SimpleParallelAnalyzerSettings();

    virtual bool SetSettingsFromInterfaces();
    void UpdateInterfacesFromSettings();
    virtual void LoadSettings( const char* settings );
    virtual const char* SaveSettings();

    U32 EnabledChannels() { return num_used_channels; }

    std::vector<Channel> mDataChannels;
    Channel mClockChannel;
    Channel mChipSelectChannel;

    ParallelAnalyzerClockEdge mClockEdge;

  protected:
    std::vector<AnalyzerSettingInterfaceChannel*> mDataChannelsInterface;
    U32 num_used_channels;

    std::unique_ptr<AnalyzerSettingInterfaceChannel> mClockChannelInterface;
    std::unique_ptr<AnalyzerSettingInterfaceChannel> mChipSelectChannelInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mClockEdgeInterface;
};

#endif // SIMPLEPARALLEL_ANALYZER_SETTINGS
