# LiveSplit.HarryPotter

Load removal and autosplitting for Harry Potter 1-3 (PC). Continued from [Dalet/LiveSplit.UnrealLoads](https://github.com/Dalet/LiveSplit.UnrealLoads).


## Building

`dotnet build -c Release -p:LiveSplitDir=<path to LiveSplit folder>` writes `Components/LiveSplit.HarryPotter.dll`.

The DLL is build attested:
```
gh attestation verify LiveSplit.HarryPotter.dll --repo FleckiBunti/LiveSplit.HarryPotter
```
