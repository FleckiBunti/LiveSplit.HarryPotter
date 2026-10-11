using LiveSplit.Model;
using LiveSplit.UI.Components;
using LiveSplit.UnrealLoads.Games;
using System;
using System.Collections.Generic;
using System.Reflection;

namespace LiveSplit.UnrealLoads
{
	public class UnrealLoadsFactory : IComponentFactory
	{
		public string ComponentName => "Harry Potter Loads";

		public string Description => "Autosplitting and load removal for Harry Potter 1-3 (PC) and some other Unreal Engine games";

		public ComponentCategory Category => ComponentCategory.Control;

		public IComponent Create(LiveSplitState state) => new UnrealLoadsComponent(state,
			new TimerModel { CurrentState = state },
			new GameMemory(_supportedGames),
			new UnrealLoadsSettings(state, _supportedGames));

		public string UpdateName => ComponentName;

		public string UpdateURL => "https://raw.githubusercontent.com/FleckiBunti/LiveSplit.HarryPotter/main/";

		public Version Version => Assembly.GetExecutingAssembly().GetName().Version;

		public string XMLURL => UpdateURL + "Components/update.LiveSplit.HarryPotter.xml";

		private readonly IList<GameSupport> _supportedGames = new GameSupport[]
		{
			new HarryPotter1(),
			new HarryPotter2(),
			new HarryPotter3(),
			new Shrek2(),
			new WheelOfTime(),
			new UnrealGold(),
			new SplinterCell3(),
			new SplinterCell(),
			new MobileForces(),
			new XCOM_Enforcer(),
			new DS9TheFallen(),
			new KlingonHonorGuard(),
			new TheHeatOfWar() 
		};
	}
}
