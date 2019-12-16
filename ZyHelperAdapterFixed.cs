using System.Globalization;
using Turbo.Plugins.Default;
using System.Linq;
using SharpDX.DirectInput;
using SharpDX.DirectWrite;

using System;
using System.Text;
using System.Windows;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace Turbo.Plugins.Zy
{
    public class ZyHelperBetaAdapter : BasePlugin, IInGameTopPainter, IKeyEventHandler
    {
        public TopLabelDecorator logoDecorator { get; set; }
        private readonly int[] _skillOrder = { 2, 3, 4, 5, 0, 1 };
        public bool Show { get; set; }
        public IKeyEvent ToggleKeyEvent { get; set; }
        public Key HotKey
        {
            get { return ToggleKeyEvent.Key; }
            set { ToggleKeyEvent = Hud.Input.CreateKeyEvent(true, value, false, false, false); }
        }
        private StringBuilder textBuilder;
        private IFont Font;
        public byte[] Bytes = new Byte[8];
        public byte[] oldBytes = new Byte[8];
        DataObject data = new DataObject();
        public ZyHelperBetaAdapter()
        {
            Enabled = true;
        }

        public override void Load(IController hud)
        {
            base.Load(hud);

            string textFunc() => "               patrick no1";
            logoDecorator = new TopLabelDecorator(Hud)
            {
                TextFont = Hud.Render.CreateFont("tahoma", 8, 255, 177, 52, 235, true, false, false),
                TextFunc = textFunc,
            };

            HotKey = Key.F11;
            Show = false;
            Font = Hud.Render.CreateFont("tahoma", 8, 255, 146, 99, 6, true, false, false);
            textBuilder = new StringBuilder();
        }

        public void OnKeyEvent(IKeyEvent keyEvent)
        {
            if (keyEvent.IsPressed && ToggleKeyEvent.Matches(keyEvent))
            {
                Show = !Show;
            }
        }

        private string ByteArrayToString(byte[] arr)
        {
            var enc = new System.Text.ASCIIEncoding();
            return enc.GetString(arr);
        }

        public bool arraysAreEqual(byte[] a1, byte[] b1)
        {
           if (a1[0] != b1[0]) return false;
           if (a1[1] != b1[1]) return false; 
           if (a1[2] != b1[2]) return false;
           if (a1[3] != b1[3]) return false;
           if (a1[4] != b1[4]) return false;
           if (a1[5] != b1[5]) return false;
           if (a1[6] != b1[6]) return false;
           if (a1[7] != b1[7]) return false;
           return true;
        }

        public void PaintTopInGame(ClipState clipState)
        {
            bool IPOnCooldown = false;
            bool WarCryOnCooldown = false;
            float NecroDistance = 0.0f;
            float WizDistance = 0.0f;
            float MonkDistance = 0.0f;
            float ChargeBarbDistance = 0.0f;
            float Rat1Distance = 0.0f;
            float Rat2Distance = 0.0f;
            bool Active = false;
            bool FalterOnCooldown = false;
            bool BerserkerOnCooldown = false;
            bool ImBarb = false;
            bool ImWizard = false;
            bool ImMonk = false;
            bool ImNecro = false;
            bool EpiphanyOnCooldown = false;
            bool MantraOfHealingOnCooldown = false;
            bool WarCryBuffActive = false;
            bool BerserkerBuffActive = false;
            bool EpiphanyBuffActive = false;
            bool LotDOnCooldown = false;
            bool LotDBuffActive = false;
            bool SprintOnCooldown = false;
            bool SprintBuffActive = false;
            bool WizardIngame = false;
            bool MonkIngame = false;
            int NecrosIngame = 0;
            bool BarbIngame = false;
            bool RecastSweepingWind = false;
            bool BohOnCooldown = false;
            bool BoneArmorAlmostRunningOut = false;
            bool BoneArmorOnCooldown = false;
            bool ConventionLight = false;
            bool ConventionArcane = false;
            bool ConventionCold = false;
            bool ConventionFire = false;
            bool ConventionPhysical = false;
            bool ConventionHoly = false;
            bool BlackholeBuffActive = false;
            bool StormArmorOnCooldown = false;
            bool StormArmorBuffActive = false;
            bool MagicWeaponOnCooldown = false;
            bool MagicWeaponBuffActive = false;
            bool BossIsSpawned = false;
            bool NatBuffActive = false;
            bool ImDh = false;
            bool ImSader = false;
            bool VengeanceBuffActive = false;
            bool VengeanceOnCooldown = false;
            bool RainOfVengeanceOnCooldown = false;
            bool PreparationOnCooldown = false;
            bool ChilanikBuff = false;
            bool BarbHasValidActor = false;
            int  NumberOfSkeleMages = 0;
            bool EliteInRange = false;
            bool SimBuffActive = false;
            bool SimOnCooldown = false;
            bool DontCastSim = false;
            bool CastSimInChanneling = false;
            bool InARift = false;
            bool ImZnec = false;
            bool ArchonBuffActive = false;
            bool ArcaneBlastOnCooldown = false;
            bool ExplosiveBlastOnCooldown = false;
            bool BloodNovaOnCooldown = false;
            bool Rat1Dead = false;
            bool Rat2Dead = false;
            double SimCD = 120.0d;
            bool PartyIsBuffable = true;
			bool ChannelingAfterDelay = false;

            bool CastIp = false;
            bool CastWc = false;
            bool CastFalter = false;
            bool CastBerserker = false;
            bool CastSprint = false;
            bool CastEpiphany = false;
            bool CastMantraHealing = false;
            bool CastSweepingWind = false;
            bool CastBoh = false;
            bool CastMantraConviction = false;
            bool CastLotd = false;
            bool CastBoneArmor = false;
            bool CastPotion = false;
            bool CastStormArmor = false;
            bool CastMagicWeapon = false;
            bool CastVengeance = false;
            bool CastRainOfVengeance = false;
            bool CastPreparation = false;
            bool CastSkeleMages = false;
            bool CastSim = false;
            bool ForceMove = false;
            bool CastArcaneBlast = false;
            bool CastExplosiveBlast = false;
			bool CastBloodNova = false;
            bool CastAkarat = false;
            bool CastIronSkin = false;
            bool CastLaw = false;
            bool CastBattleRage = false;
            bool CastCOTA = false;
            bool AkaratOnCooldown = false;
            bool IronSkinOnCooldown = false;
            bool LawOnCooldown = false;
            bool AkaratIsActive = false;
            bool IronSkinIsActive = false;
            bool BattleRageIsActive = false;
            bool COTAIsActive = false;          // Call of the ancients
            bool COTAOnCooldown = false;
            bool CastShieldGlareJudgment = false;
            bool ShieldGlareJudgmentEquipped = false;
            bool ShieldGlareJudgmentOnCooldown = false;
            bool FistOfHeavensEquipped = false;
            bool RecastFistOfHeavens = false;
            bool CastFistOfHeavens = false;


            bool IpEquipped = false;
            bool WcEquipped = false;
            bool FalterEquipped = false;
            bool BerserkerEquipped = false;
            bool SprintEquipped = false;
            bool EpiphanyEquipped = false;
            bool MantraHealingEquipped = false;
            bool SweepingWindEquipped = false;
            bool BohEquipped = false;
            bool MantraConvictionEquipped = false;
            bool LotdEquipped = false;
            bool BoneArmorEquipped = false;
            bool StormArmorEquipped = false;
            bool MagicWeaponEquipped = false;
            bool VengeanceEquipped = false;
            bool RainOfVengeanceEquipped = false;
            bool PreparationEquipped = false;
            bool SkeleMagesEquipped = false;
            bool SimEquipped = false;
            bool ArchonEquipped = false;
            bool ExplosiveBlastEquippped = false;
            bool BloodNovaEquipped = false;
            bool AkaratEquipped = false;
            bool IronSkinEquipped = false;
            bool LawEquipped = false;
            bool BattleRageEquipped = false;
            bool COTAEquipped = false;

            IWorldCoordinate MyPosition = Hud.Game.Players.First().FloorCoordinate;
            IWorldCoordinate WizPosition = Hud.Game.Players.First().FloorCoordinate;
            IWorldCoordinate MonkPosition = Hud.Game.Players.First().FloorCoordinate;
            IWorldCoordinate NecroPosition = Hud.Game.Players.First().FloorCoordinate;
            IWorldCoordinate ChargeBarbPosition = Hud.Game.Players.First().FloorCoordinate;
            IWorldCoordinate Rat1Position = Hud.Game.Players.First().FloorCoordinate;
            IWorldCoordinate Rat2Position = Hud.Game.Players.First().FloorCoordinate;

            BossIsSpawned = (Hud.Game.AliveMonsters.Count(m => m.SnoMonster.Priority == MonsterPriority.boss) > 0);

            int Range15Enemies = 0;
            int Range25Enemies = 0;
            int Range75Enemies = 0;

            var monsters2 = Hud.Game.AliveMonsters.Where(m => ((m.SummonerAcdDynamicId == 0 && m.IsElite) || !m.IsElite));
            foreach (var monster in monsters2)
            {
                if (monster.FloorCoordinate.XYDistanceTo(Hud.Game.Me.FloorCoordinate) <= 15) Range15Enemies++;
                if (monster.FloorCoordinate.XYDistanceTo(Hud.Game.Me.FloorCoordinate) <= 25) Range25Enemies++;
                if (monster.FloorCoordinate.XYDistanceTo(Hud.Game.Me.FloorCoordinate) <= 75) Range75Enemies++;

                
                if ((monster.Rarity == ActorRarity.Unique) ||
                    (monster.Rarity == ActorRarity.Champion) ||
                    (monster.Rarity == ActorRarity.Rare) ||
                    (monster.SnoMonster.Priority == MonsterPriority.boss) ||
                    (monster.SnoActor.Sno == ActorSnoEnum._x1_pand_ext_ordnance_tower_shock_a))//shocktower
                {
                    if (monster.FloorCoordinate.XYDistanceTo(Hud.Game.Me.FloorCoordinate) <= 70)
                    {
                        EliteInRange = true;
                    }
                }
            }

            foreach (var player in Hud.Game.Players)//me
            {
                if (!player.IsMe) continue;
                MyPosition = player.FloorCoordinate;

                foreach (var i in _skillOrder)
                {
                    var skill = player.Powers.SkillSlots[i];
                    if (skill == null ) continue;
                    //barb
                    if (skill.SnoPower.Sno == 79528)//Barbarian_IgnorePain
                    {
                        IPOnCooldown = skill.IsOnCooldown;
                        IpEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 375483)// Barbarian_WarCry
                    {
                        WarCryBuffActive = skill.BuffIsActive;
                        WarCryOnCooldown = skill.IsOnCooldown;
                        WcEquipped = true;
                        var buff = player.Powers.GetBuff(318821); //ChilaniksChain 318821 - ItemPassive_Unique_Ring_639_x1
                        if ((buff == null) || (buff.IconCounts[0] <= 0)) continue;
                        ChilanikBuff = buff.TimeLeftSeconds[1] > 0.0;
                        
                    }
                    if (skill.SnoPower.Sno == 79077)// Barbarian_ThreateningShout
                    {
                        FalterOnCooldown = skill.IsOnCooldown;
                        FalterEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 79607)// Barbarian_WrathOfTheBerserker
                    {
                        BerserkerBuffActive = skill.BuffIsActive;
                        BerserkerOnCooldown = skill.IsOnCooldown;
                        BerserkerEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 78551)// Barbarian_Sprint
                    {
                        SprintOnCooldown = skill.IsOnCooldown;
                        SprintEquipped = true;
						
						var buff = skill.Buff;
                        if ((buff == null) || (buff.IconCounts[0] <= 0)) continue;
                        SprintBuffActive = buff.TimeLeftSeconds[0] > 2.0;
                    }
                    if (skill.SnoPower.Sno == 79076)// Barbarian_BattleRage
                    {
                        BattleRageEquipped = true;

                        BattleRageIsActive = skill.BuffIsActive;
                    }
                    if (skill.SnoPower.Sno == 80049)// Barbarian_CallOfTheAncients
                    {
                        COTAOnCooldown = skill.IsOnCooldown;
                        COTAEquipped = true;

                        COTAIsActive = skill.BuffIsActive;
                    }

                    //monk
                    if (skill.SnoPower.Sno == 312307)//Monk_Epiphany
                    {
                        EpiphanyEquipped = true;
                        EpiphanyOnCooldown = skill.IsOnCooldown;
                        var buff = skill.Buff;
                        if ((buff == null) || (buff.IconCounts[0] <= 0)) continue;
                        EpiphanyBuffActive = buff.TimeLeftSeconds[0] > 0.5;
                    }
                    if (skill.SnoPower.Sno == 373143)//Monk_MantraOfHealing
                    {
                        MantraOfHealingOnCooldown = skill.IsOnCooldown;
                        MantraHealingEquipped = true;
                    }

                    if (skill.SnoPower.Sno == 96090)//Monk_SweepingWind
                    {
                        SweepingWindEquipped = true;
						var buff = skill.Buff;
						if ((buff == null) || (buff.IconCounts[0] <= 0)) 
						{
							RecastSweepingWind = true;
							continue;
						}
						RecastSweepingWind = skill.Buff.TimeLeftSeconds[0] < 1.0;
                        
                    }

                    if (skill.SnoPower.Sno == 69130)//Monk_BreathOfHeaven
                    {
                        BohOnCooldown = skill.IsOnCooldown;
                        BohEquipped = true;
                    }

                    if (skill.SnoPower.Sno == 375088)//Monk_MantraOfConviction
                    {
                        MantraConvictionEquipped = true;
                    }

                    //wizard
                    if (skill.SnoPower.Sno == 74499)//Wizard_StormArmor
                    {
                        StormArmorBuffActive = skill.BuffIsActive;
                        StormArmorOnCooldown = skill.IsOnCooldown;
                        StormArmorEquipped = true;
                    }

                    if (skill.SnoPower.Sno == 76108)//Wizard_MagicWeapon
                    {
                        MagicWeaponBuffActive = skill.BuffIsActive;
                        MagicWeaponOnCooldown = skill.IsOnCooldown;
                        MagicWeaponEquipped = true;
                    }

                    if (skill.SnoPower.Sno == 134872)//Wizard_Archon
                    {
                        var buff = player.Powers.GetBuff(Hud.Sno.SnoPowers.Wizard_Archon.Sno);
                        if (buff != null)
                        {
                            ArchonBuffActive = buff.TimeLeftSeconds[2] > 0.1;
                        }
                        ArchonEquipped = true;
                    }

                    if (skill.SnoPower.Sno == 87525)//Wizard_ExplosiveBlast { get; } // 87525
                    {
                        ExplosiveBlastOnCooldown = skill.IsOnCooldown;
                        ExplosiveBlastEquippped = true;
                    }

                    if (i == 2)
                    {
                        ArcaneBlastOnCooldown = skill.IsOnCooldown;
                    }

                    /*if (skill.SnoPower.Sno == 392885 || skill.SnoPower.Sno == 167355)//Wizard_ArchonArcaneBlastLightning Wizard_ArchonArcaneBlast
                    {
                        ArcaneBlastOnCooldown = skill.IsOnCooldown;
                    }*/


                    //necro
                    if (skill.SnoPower.Sno == 466857)//Necromancer_BoneArmor
                    {
                        BoneArmorOnCooldown = skill.IsOnCooldown;
                        BoneArmorEquipped = true;
                        if (skill.Buff != null)
                        {
                            BoneArmorAlmostRunningOut = skill.Buff.TimeLeftSeconds[0] < 30.0;
                        }
                       
                    }
					if (skill.SnoPower.Sno == 465839)//Necromancer_LandOfTheDead { get; }
                    {
                        //LotDBuffActive = skill.BuffIsActive;
                        LotDOnCooldown = skill.IsOnCooldown;
                        LotdEquipped = true;
						var buff = skill.Buff;
                        if ((buff == null) || (buff.IconCounts[0] <= 0)) continue;
                        LotDBuffActive = buff.TimeLeftSeconds[0] > 0.5;
                    }
                    
                    if (skill.SnoPower.Sno == 462089)//Necromancer_SkeletalMage { get; }
                    {
                        SkeleMagesEquipped = true;
                        HashSet<ActorSnoEnum> SkeletonMageActorSNOs = new HashSet<ActorSnoEnum>
                        {
                            ActorSnoEnum._p6_necro_skeletonmage_a, // Skeleton Mage - No Rune
                            ActorSnoEnum._p6_necro_skeletonmage_b, // Skeleton Mage - Gift of Death
                            ActorSnoEnum._p6_necro_skeletonmage_e, // Skeleton Mage - Contamination
                            ActorSnoEnum._p6_necro_skeletonmage_f_archer, // Skeleton Mage - Archer
                            ActorSnoEnum._p6_necro_skeletonmage_c, // Skeleton Mage - Singularity
                           ActorSnoEnum. _p6_necro_skeletonmage_d  // Skeleton Mage - Life Support
                        };
                        var SkeletonMageActors = Hud.Game.Actors.Where(EachActor => SkeletonMageActorSNOs.Contains(EachActor.SnoActor.Sno) && // Find out which are skeleton mages actors
                                        EachActor.SummonerAcdDynamicId == Hud.Game.Me.SummonerId); // Then find out if they are summoned by the player
                        NumberOfSkeleMages = SkeletonMageActors.Count(); // And then count how many are found
                    }
                    
                    if (skill.SnoPower.Sno == 465350)//Necromancer_Simulacrum { get; }
                    {
                        SimOnCooldown = skill.IsOnCooldown;
                        SimEquipped = true;
                        var buff = skill.Buff;
                        if ((buff == null) || (buff.IconCounts[0] <= 0)) continue;
                        SimBuffActive = buff.TimeLeftSeconds[0] > 0.0;
                    }

                    if (skill.SnoPower.Sno == 462243)//Necromancer_DeathNova { get; } // 462243
                    {
                        BloodNovaOnCooldown = skill.IsOnCooldown;
                        BloodNovaEquipped = true;
                    }

                    //dh
                    if (skill.SnoPower.Sno == 302846)//DemonHunter_Vengeance { get; }
                    {
						VengeanceOnCooldown = skill.IsOnCooldown;
                        VengeanceEquipped = true;
                        var buff = skill.Buff;
                        if ((buff == null) || (buff.IconCounts[0] <= 0)) continue;
                        VengeanceBuffActive = buff.TimeLeftSeconds[0] > 0.5;
                        
                    }
                    if (skill.SnoPower.Sno == 130831)//DemonHunter_RainOfVengeance { get; }
                    {
                        RainOfVengeanceOnCooldown = skill.IsOnCooldown;
                        RainOfVengeanceEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 129212)//DemonHunter_Preparation { get; }
                    {
                        PreparationOnCooldown = skill.IsOnCooldown;
                        PreparationEquipped = true;
                    }

                    // crus
                    if (skill.SnoPower.Sno == 269032) // Crusader_AkaratsChampion
                    {
                        AkaratIsActive = skill.BuffIsActive;
                        AkaratOnCooldown = skill.IsOnCooldown;
                        AkaratEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 291804) // Crusader_IronSkin
                    {
                        IronSkinIsActive = skill.BuffIsActive;
                        IronSkinOnCooldown = skill.IsOnCooldown;
                        IronSkinEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 342279 || skill.SnoPower.Sno == 342280 || skill.SnoPower.Sno == 342281) // Crusader_LawsOfHope || Crusader_LawsOfJustice || Crusader_LawsOfValor
                    {
                        LawOnCooldown = skill.IsOnCooldown;
                        LawEquipped = true;
                    }
                    if (skill.SnoPower.Sno == 239218) // Fist of heavens
                    {

                        FistOfHeavensEquipped = true;
                        var power = player.Powers.GetBuff(483643);             
                        if (power != null)
                        {
                            if (power.IconCounts[1] < 3 || power.TimeLeftSeconds[1] <= 0.8)
                            {
                                RecastFistOfHeavens = true;
                            }
                        
                        }
                        // var power = Hud.Game.Me.Powers.AllBuffs.FirstOrDefault(curr => curr.SnoPower.Sno == 483643 && curr.TimeLeftSeconds[1] > 0);

                    }
                    if (skill.SnoPower.Sno == 268530 || skill.SnoPower.Sno == 267600) // shield glare OR judgment
                    {
                       
                        ShieldGlareJudgmentEquipped = true;
                        ShieldGlareJudgmentOnCooldown = skill.IsOnCooldown;
                    }
                }
            }

            int RatsFound = 0;
            foreach (var player in Hud.Game.Players)//others
            {

                if (player.HeroClassDefinition.HeroClass == HeroClass.Barbarian)
                {
                    if (player.IsMe)
                    {
                        ImBarb = true;
                    }
                    else
                    {
                        BarbIngame = true;
                        BarbHasValidActor = player.HasValidActor;
                        var EfficaciousToxin = player.Powers.GetBuff(403461);
                        if (EfficaciousToxin == null || !EfficaciousToxin.Active)
                        {
                            //chargebarb
                            ChargeBarbPosition = player.FloorCoordinate;
                        }
                        else
                        {
                            //zbarb
                        }
                    }
                }
                if (player.HeroClassDefinition.HeroClass == HeroClass.Wizard)
                {
                    if (player.IsMe)
                    {
                        ImWizard = true;
                        IBuff ConventionBuff = player.Powers.GetBuff(430674);
                        if ((ConventionBuff == null) || (ConventionBuff.IconCounts[0] <= 0)) continue;

                        ConventionLight = ConventionBuff.IconCounts[5] != 0;
                        ConventionArcane = ConventionBuff.IconCounts[1] != 0;
                        ConventionCold = ConventionBuff.IconCounts[2] != 0;
                        ConventionFire = ConventionBuff.IconCounts[3] != 0;

                        IBuff BlackholeBuff = player.Powers.GetBuff(243141);
                        if (BlackholeBuff == null) continue;
                        if (BlackholeBuff.IconCounts[5] <= 0) continue;

                        BlackholeBuffActive = (BlackholeBuff.TimeLeftSeconds[5] > 3.5);
                    }
                    else
                    {
                        WizPosition = player.FloorCoordinate;
                        WizardIngame = true;
                    }
					
					var LoadingBuff = player.Powers.GetBuff(212032);
					if (!(LoadingBuff == null || !LoadingBuff.Active))
					{
						PartyIsBuffable = false;
					}
					var GhostedBuff = player.Powers.GetBuff(224639);
					if (!(GhostedBuff == null || !GhostedBuff.Active))
					{
						PartyIsBuffable = false;
					}
					var InvulBuff = player.Powers.GetBuff(439438);
					if (!(InvulBuff == null || !InvulBuff.Active))
					{
						PartyIsBuffable = false;
					}
					var UntargetableDuringBuff = player.Powers.GetBuff(30582);
					if (!(UntargetableDuringBuff == null || !UntargetableDuringBuff.Active))
					{
						PartyIsBuffable = false;
					}
                }
                if (player.HeroClassDefinition.HeroClass == HeroClass.Monk)
                {
                    if (player.IsMe)
                    {
                        ImMonk = true;
                    }
                    else
                    {
                        MonkPosition = player.FloorCoordinate;
                        MonkIngame = true;
                    }
                }
                if (player.HeroClassDefinition.HeroClass == HeroClass.Necromancer)
                {
                    var EfficaciousToxin = player.Powers.GetBuff(403461);
                    if (EfficaciousToxin == null || !EfficaciousToxin.Active)
                    {
                        //rat
                        if (player.IsMe)
                        {
                            ImZnec = false;
							ImNecro = true;
                        }
                        else
                        {
                            if (RatsFound == 0)
                            {
                                Rat1Dead = player.IsDead;
                                Rat1Position = player.FloorCoordinate;
                                RatsFound = 1;
                            }
                            else if (RatsFound == 1)
                            {
                                Rat2Dead = player.IsDead;
                                Rat2Position = player.FloorCoordinate;
                                RatsFound = 2;
                            }
                            NecroPosition = player.FloorCoordinate;
                        }
                    }
                    else
                    {
                        //znec
                        if (player.IsMe)
                        {
                            ImZnec = true;
							ImNecro = true;
                        }
                    }

                    foreach (var i in _skillOrder)
                    {
                        var skill = player.Powers.SkillSlots[i];
                        if (skill.SnoPower.Sno == 465350)//Necromancer_Simulacrum { get; }
                        {
                            var CurrentSimCD = skill.CalculateCooldown(120);
                            if (CurrentSimCD < SimCD)
                            {
                                SimCD = CurrentSimCD;
                            }
                            break;
                        }

                    }

                    NecrosIngame++;
                }
                if (player.HeroClassDefinition.HeroClass == HeroClass.DemonHunter)
                {
                    if (player.IsMe)
                    {
                        ImDh = true;
                        IBuff NatBuff = player.Powers.GetBuff(434964);
                        if (NatBuff == null) continue;
                        NatBuffActive = (NatBuff.TimeLeftSeconds[1] > 0.5);
                    }
                    else
                    {
                        //
                    }
                }
                if (player.HeroClassDefinition.HeroClass == HeroClass.Crusader)
                {
                    if (player.IsMe)
                    {
                        ImSader = true;
                        IBuff ConventionBuff = player.Powers.GetBuff(430674);
                        if ((ConventionBuff == null) || (ConventionBuff.IconCounts[0] <= 0))
                            continue;

                        var coelen = ConventionBuff.IconCounts.Count();
                        ConventionFire = ConventionBuff.IconCounts[3] != 0;
                        ConventionHoly = ConventionBuff.IconCounts[4] != 0;
                        ConventionLight = ConventionBuff.IconCounts[5] != 0;
                        ConventionPhysical = ConventionBuff.IconCounts[6] != 0;

                    }
                    else
                    {
                        //
                    }
                }

                
            }

            WizDistance = WizPosition.XYDistanceTo(MyPosition);
            MonkDistance = MonkPosition.XYDistanceTo(MyPosition);
            NecroDistance = NecroPosition.XYDistanceTo(MyPosition);
            ChargeBarbDistance = ChargeBarbPosition.XYDistanceTo(MyPosition);
            Rat1Distance = Rat1Position.XYDistanceTo(MyPosition);
            Rat2Distance = Rat2Position.XYDistanceTo(MyPosition);

            var Channelingbuff = Hud.Game.Me.Powers.GetBuff(266258);
            if ((Channelingbuff != null) && (Channelingbuff.IconCounts[0] > 0))
            {
                CastSimInChanneling = (Channelingbuff.TimeLeftSeconds[0] < 2.0d) || (Channelingbuff.TimeLeftSeconds[0] > 28.0d);
                ChannelingAfterDelay = Channelingbuff.TimeLeftSeconds[0] < 28.0d;
            }

            var TargetedMonster = Hud.Game.SelectedMonster2 ?? Hud.Game.SelectedMonster1;
            bool EliteTargeted = false;
            if (TargetedMonster != null)
            {
                //EliteTargeted = TargetedMonster.IsElite;
                EliteTargeted = (TargetedMonster.Rarity == ActorRarity.Unique) ||
                                (TargetedMonster.Rarity == ActorRarity.Champion) ||
                                (TargetedMonster.Rarity == ActorRarity.Rare) ||
                                (TargetedMonster.SnoMonster.Priority == MonsterPriority.boss) ||
                                (TargetedMonster.SnoActor.Sno == ActorSnoEnum._x1_pand_ext_ordnance_tower_shock_a);//shocktower
            }


            InARift = (Hud.Game.SpecialArea == SpecialArea.Rift || Hud.Game.SpecialArea == SpecialArea.GreaterRift);
			
            Active = true;
            Active = Active && Hud.Game.IsInGame;
            Active = Active && !Hud.Game.IsLoading;
            Active = Active && !Hud.Game.IsInTown;
            Active = Active && !Hud.Game.Me.IsDead;
            Active = Active && !Hud.Render.UiHidden;
            Active = Active && Hud.Game.MapMode == MapMode.Minimap;
            Active = Active && (Hud.Game.Me.AnimationState != AcdAnimationState.CastingPortal && Hud.Game.Me.AnimationState != AcdAnimationState.Dead);

            bool GRGuardianIsDead = false;
            var riftQuest = Hud.Game.Quests.FirstOrDefault(q => q.SnoQuest.Sno == 337492) ??
                            Hud.Game.Quests.FirstOrDefault(q => q.SnoQuest.Sno == 382695);
            if (riftQuest != null)
            {
                if (Hud.Game.Monsters.Any(m => m.Rarity == ActorRarity.Boss && !m.IsAlive))
                {
                    GRGuardianIsDead = true;
                }
                else
                {
                    GRGuardianIsDead = (riftQuest.QuestStepId == 34 || riftQuest.QuestStepId == 46);
                };
            }

            Active = Active && !GRGuardianIsDead;


            double Cooldown = (Hud.Game.Me.Powers.HealthPotionSkill.CooldownFinishTick - Hud.Game.CurrentGameTick) / 60d;
            bool PotionIsOnCooldown = Cooldown <= 30 && Cooldown >= 0 ? true : false;

            bool WizInIpRange;
            if (WizardIngame && MonkIngame)//metas
            {
                if ((WizPosition.XYDistanceTo(MonkPosition) > 50) || !MonkIngame)
                {
                    WizInIpRange = (WizDistance <= 45);
                }
                else
                {
                    WizInIpRange = (Math.Max(WizDistance, MonkDistance) <= 45);
                }

                CastIp = !IPOnCooldown && IpEquipped && PartyIsBuffable && (!BossIsSpawned && WizInIpRange ||
                           BossIsSpawned && (NecroDistance <= 45));
                CastFalter = FalterEquipped && !FalterOnCooldown && (!BossIsSpawned && (WizDistance <= 20) ||
                           BossIsSpawned);
                CastWc = WcEquipped && !WarCryOnCooldown && PartyIsBuffable && (!ChilanikBuff || NecroDistance <= 100);
            }
            else if (NecrosIngame == 3)//rats
            {
                CastIp = !IPOnCooldown && IpEquipped && PartyIsBuffable;
                if (!Rat1Dead)
                {
                    CastIp = CastIp && (Rat1Distance <= 45);
                }
                if (!Rat2Dead)
                {
                    CastIp = CastIp && (Rat2Distance <= 45);
                }
                CastFalter = FalterEquipped && !FalterOnCooldown;
                CastWc = WcEquipped && !WarCryOnCooldown && PartyIsBuffable;
            }
            else
            {
                CastIp = !IPOnCooldown && IpEquipped && PartyIsBuffable && (Hud.Game.NumberOfPlayersInGame == (Hud.Game.Players.Where(p => p.CentralXyDistanceToMe <= 45)).Count());
                CastFalter = FalterEquipped && !FalterOnCooldown;
                CastWc = (WcEquipped && !WarCryOnCooldown && PartyIsBuffable && (!ChilanikBuff || (Hud.Game.NumberOfPlayersInGame == (Hud.Game.Players.Where(p => p.CentralXyDistanceToMe <= 45)).Count())));
            }
            
            


            CastBerserker = BerserkerEquipped && !BerserkerOnCooldown && !BerserkerBuffActive;
            CastSprint = SprintEquipped && !SprintOnCooldown && Hud.Game.Me.Stats.ResourceCurFury >= 20 && !SprintBuffActive;
            CastBattleRage = BattleRageEquipped && Hud.Game.Me.Stats.ResourceCurFury >= 20 && !BattleRageIsActive;
            CastCOTA = COTAEquipped && !COTAOnCooldown && !COTAIsActive;
            CastEpiphany = EpiphanyEquipped && !EpiphanyOnCooldown && !EpiphanyBuffActive;
            CastMantraHealing = MantraHealingEquipped && !MantraOfHealingOnCooldown && Hud.Game.Me.Stats.ResourceCurSpirit >= (0.3 * Hud.Game.Me.Stats.ResourceMaxSpirit) && (Range75Enemies >= 1);
            CastSweepingWind = SweepingWindEquipped && RecastSweepingWind && Hud.Game.Me.Stats.ResourceCurSpirit >= (Hud.Game.Me.Stats.ResourceMaxSpirit / 2.0);
            CastBoh = BohEquipped && !BohOnCooldown && ((Hud.Game.SpecialArea == SpecialArea.Rift) || BarbIngame && (ChargeBarbDistance <= 12) && BarbHasValidActor);
            CastMantraConviction = MantraConvictionEquipped && Hud.Game.Me.Stats.ResourceCurSpirit >= (Hud.Game.Me.Stats.ResourceMaxSpirit / 2.0);
            CastLotd = LotdEquipped && !LotDOnCooldown && !LotDBuffActive && (Range75Enemies >= 1);
            //CastBoneArmor = BoneArmorEquipped && (((BoneArmorAlmostRunningOut && (Range25Enemies >= 1)) ||
            //                  (!BoneArmorAlmostRunningOut && (Range25Enemies >= 5))) &&
            //                  !BoneArmorOnCooldown);
            CastBoneArmor = BoneArmorEquipped && (Range25Enemies >= 1) && !BoneArmorOnCooldown;
			
            DontCastSim = (((Hud.Game.CurrentTimedEventEndTick - (double)Hud.Game.CurrentGameTick) / 60.0d) > (900.0d - SimCD*0.4)) || ChannelingAfterDelay;
			if(Hud.Game.SpecialArea == SpecialArea.Rift) DontCastSim = false;
			
            CastSim = InARift && SimEquipped && !SimOnCooldown && (!(Hud.Game.Me.Stats.ResourceMaxEssence > 450) || CastSimInChanneling);//have sim because of reservoir
            CastPotion = Hud.Game.Me.Defense.HealthCur <= (Hud.Game.Me.Defense.HealthMax * 0.35) && !PotionIsOnCooldown;
            CastStormArmor = !ArchonBuffActive && StormArmorEquipped && !StormArmorOnCooldown && !StormArmorBuffActive;
            CastMagicWeapon = !ArchonBuffActive && MagicWeaponEquipped && !MagicWeaponOnCooldown && !MagicWeaponBuffActive;
            CastVengeance = VengeanceEquipped && !VengeanceOnCooldown && !VengeanceBuffActive;
            CastRainOfVengeance = RainOfVengeanceEquipped && !RainOfVengeanceOnCooldown && !NatBuffActive;
            CastPreparation = PreparationEquipped && !PreparationOnCooldown && !(Hud.Game.Me.Stats.ResourceCurDiscipline >= (Hud.Game.Me.Stats.ResourceMaxDiscipline - 30));
            ForceMove = InARift && !ImZnec && (Hud.Game.Me.AnimationState == AcdAnimationState.Idle || Hud.Game.Me.AnimationState == AcdAnimationState.Casting);
            CastArcaneBlast = ArchonBuffActive && ArchonEquipped && !ArcaneBlastOnCooldown && (Range15Enemies > 0);
            CastExplosiveBlast = !ArchonBuffActive && ExplosiveBlastEquippped && !ExplosiveBlastOnCooldown && Hud.Game.Me.Stats.ResourceCurArcane >= (Hud.Game.Me.Stats.ResourceMaxArcane / 3.0);
            CastBloodNova = /*InARift && */BloodNovaEquipped && !BloodNovaOnCooldown && (Hud.Game.Me.Stats.ResourceCurEssence >= (Hud.Game.Me.Stats.ResourceMaxEssence / 3.0)) && (Range25Enemies >= 1);

            CastAkarat = AkaratEquipped && !AkaratOnCooldown && !AkaratIsActive;
            CastIronSkin = IronSkinEquipped && !IronSkinOnCooldown && !IronSkinIsActive;
            CastLaw = LawEquipped && !LawOnCooldown;
            CastFistOfHeavens = FistOfHeavensEquipped && RecastFistOfHeavens;
            CastShieldGlareJudgment = ShieldGlareJudgmentEquipped && !ShieldGlareJudgmentOnCooldown;



            if (BossIsSpawned || Hud.Game.SpecialArea == SpecialArea.Rift)
			{
				CastSkeleMages = InARift && SkeleMagesEquipped && (Hud.Game.Me.Stats.ResourceCurEssence >= (Hud.Game.Me.Stats.ResourceMaxEssence*0.95)) && (NumberOfSkeleMages < 10);
            }
			else
			{
				CastSkeleMages = InARift && SkeleMagesEquipped && (Hud.Game.Me.Stats.ResourceCurEssence >= (Hud.Game.Me.Stats.ResourceMaxEssence*0.95)) && (EliteInRange && EliteTargeted || (!EliteInRange) && (NumberOfSkeleMages < 10));
			}

            var bitArray = new BitArray(8);

            bitArray.Set(0, true);
            bitArray.Set(1, Active);
            bitArray.Set(2, ImBarb);
            bitArray.Set(3, ImMonk);
            bitArray.Set(4, ImWizard);
            bitArray.Set(5, ImNecro);
            bitArray.Set(6, ImDh);
            
            bitArray.CopyTo(Bytes, 0);


            bitArray.Set(0, true);
            bitArray.Set(1, ConventionLight);
            bitArray.Set(2, ConventionArcane);
            bitArray.Set(3, ConventionCold);
            bitArray.Set(4, ConventionFire);
            bitArray.Set(5, BlackholeBuffActive);
            bitArray.Set(6, CastArcaneBlast);
            bitArray.Set(7, false);

            bitArray.CopyTo(Bytes, 1);


            bitArray.Set(0, true);
            bitArray.Set(1, InARift);
            bitArray.Set(2, WarCryBuffActive);
            bitArray.Set(3, BerserkerBuffActive);
            bitArray.Set(4, EpiphanyBuffActive);
            bitArray.Set(5, ImSader);
            bitArray.Set(6, LotDBuffActive);

            bitArray.CopyTo(Bytes, 2);


            bitArray.Set(0, true);
            bitArray.Set(1, CastIp);
            bitArray.Set(2, CastSim);
            bitArray.Set(3, DontCastSim);
            bitArray.Set(4, CastFalter);
            bitArray.Set(5, CastBerserker);
            bitArray.Set(6, CastSprint);           

            bitArray.CopyTo(Bytes, 3);


            bitArray.Set(0, true);
            bitArray.Set(1, CastWc); 
            bitArray.Set(2, CastMantraHealing);
            bitArray.Set(3, CastSweepingWind);
            bitArray.Set(4, CastBoh);
            bitArray.Set(5, CastMantraConviction);
            bitArray.Set(6, CastLotd);

            bitArray.CopyTo(Bytes, 4);


            bitArray.Set(0, true);
            bitArray.Set(1, CastPotion);
            bitArray.Set(2, CastStormArmor);
            bitArray.Set(3, CastMagicWeapon);
            bitArray.Set(4, CastVengeance);
            bitArray.Set(5, CastRainOfVengeance);
            bitArray.Set(6, CastPreparation);

            bitArray.CopyTo(Bytes, 5);


            bitArray.Set(0, true);
            bitArray.Set(1, ForceMove);
            bitArray.Set(2, CastFistOfHeavens);
            bitArray.Set(3, CastShieldGlareJudgment);
            bitArray.Set(4, CastAkarat);
            bitArray.Set(5, CastIronSkin);
            bitArray.Set(6, CastLaw);

            bitArray.CopyTo(Bytes, 6);


            bitArray.Set(0, true);
            bitArray.Set(1, CastBattleRage);
            bitArray.Set(2, CastCOTA);
            bitArray.Set(3, CastEpiphany);
            bitArray.Set(4, CastBoneArmor);
            bitArray.Set(5, ConventionHoly);
            bitArray.Set(6, ConventionPhysical);

            bitArray.CopyTo(Bytes, 7);


            if (!arraysAreEqual(Bytes, oldBytes)) {
                try {
                    Clipboard.SetText(ByteArrayToString(Bytes));
                    Bytes.CopyTo(oldBytes, 0);
                } catch (Exception e) {
                    Hud.Debug(e.ToString());
                }
            }
           

            // Hud.Debug("akarat: " + CastAkarat + " iron skin: " + CastIronSkin + " cast law: " + CastLaw);


            System.Threading.Thread.Sleep(5);

            if (Hud.Render.UiHidden) return;
            float x = -Hud.Window.Size.Width * 0.001f;
            float y = Hud.Window.Size.Height * 0.965f;

            logoDecorator.Paint(x, y, 30.0f, 30.0f, HorizontalAlign.Center);

            if (Show)
            {
                float XPos = Hud.Window.Size.Width * 0.01f;
                float YPos = Hud.Window.Size.Height * 0.665f;
                textBuilder.Clear();

                Active = true;
                Active = Active && Hud.Game.IsInGame;
                Active = Active && !Hud.Game.IsPaused;
                Active = Active && !Hud.Game.IsLoading;
                Active = Active && !Hud.Game.IsInTown;
                Active = Active && !Hud.Game.Me.IsDead;
                Active = Active && !Hud.Render.UiHidden;
                Active = Active && Hud.Game.MapMode == MapMode.Minimap;
                Active = Active && (Hud.Game.Me.AnimationState != AcdAnimationState.CastingPortal && Hud.Game.Me.AnimationState != AcdAnimationState.Dead);
                Active = Active && (Hud.Game.SpecialArea == SpecialArea.Rift || Hud.Game.SpecialArea == SpecialArea.GreaterRift);

                textBuilder.AppendFormat("IsInGame: {0}", Hud.Game.IsInGame);
                textBuilder.AppendLine();
                textBuilder.AppendFormat("IsPaused: {0}", Hud.Game.IsPaused);
                textBuilder.AppendLine();
                textBuilder.AppendFormat("IsLoading: {0}", Hud.Game.IsLoading);
                textBuilder.AppendLine();
                textBuilder.AppendFormat("IsDead: {0}", Hud.Game.Me.IsDead);
                textBuilder.AppendLine();
                textBuilder.AppendFormat("UiHidden: {0}", Hud.Render.UiHidden);
                textBuilder.AppendLine();
                textBuilder.AppendFormat("Minimap: {0}", Hud.Game.MapMode == MapMode.Minimap);
                textBuilder.AppendLine();
                textBuilder.AppendFormat("dead or portal: {0}", (Hud.Game.Me.AnimationState != AcdAnimationState.CastingPortal && Hud.Game.Me.AnimationState != AcdAnimationState.Dead));
                textBuilder.AppendLine();
                textBuilder.AppendFormat("in rift: {0}", (Hud.Game.SpecialArea == SpecialArea.Rift || Hud.Game.SpecialArea == SpecialArea.GreaterRift));
                textBuilder.AppendLine();
                textBuilder.AppendFormat("current COE is on: {0}", ConventionPhysical);
                textBuilder.AppendLine();

                var layout = Font.GetTextLayout(textBuilder.ToString());
                Font.DrawText(layout, XPos, YPos);
            }
        }

    }

}