--- DIRECTORY PATH ---

    DataDir = "data/"

--- BANS ---

    NotationsToBan = 3
    WarningsToFinalBan = 4
    WarningsToDeletion = 5
    BanLength = 1 * 24 * 60 * 60
    FinalBanLength = 7 * 24 * 60 * 60
    IPBanishmentLength = 24 * 60 * 60
    KillsToBan = 7

--- COMBAT ---

    -- World type
    -- options: pvp, no-pvp, pvp-enforced
    WorldType = "pvp"

    -- Exhausted time in ms (1000 = 1 second) for yelling
    Exhausted = 1000

    -- Exhausted time in ms (1000 = 1 second) for aggressive spells/weapons
    FightExhausted = 2000

    -- Exhausted time in ms (1000 = 1 second) for none-aggressive spells/weapons
    HealExhausted = 1000

    -- How many ms to add if the player is already exhausted and tries to yell (1000 = 1 second)
    ExhaustedAdd = 200

    -- How long does the player has to stay out of fight to get pz unlocked in ms (1000 = 1 second)
    PZLock = 60000

    -- How long a field belongs to a player before it no longer causes PZ lock for the owner
    FieldOwnershipDuration = 5000

    -- In mili seconds
    TimeToDecreaseFrags = 24 * 60 * 60 * 1000

    -- Time white skull will remain after killing a player, in minutes
    WhiteSkullTime = 3

    -- amount of kills that leads to red skull
    KillsToRedSkull = 5

    -- Remove ammunition
    -- If false, ammunition will not be removed when using distance weapons
    -- (or other weapons that use ammunition)
    RemoveAmmunition = true

    -- Remove rune charges
    -- This only applies to runes done using the default functions. 
    -- Custom runes made using actions will not be affected.
    RemoveRuneCharges = true

    -- Remove weapon charges
    -- Set to false to disable charges disappearing from weapons on use
    RemoveWeaponCharges = true

    -- Top player on a stacked tile will be unable to heal
    UHTrap = true

---- CONNECTION ----

    -- Server ip (the ip that server listens on)
    IP = "127.0.0.1"

    -- Server port (the port that server listens on)
    Port = "7171"

    -- How many logins attempts until ip is temporary disabled 
    -- Set to 0 to disable
    LoginTries = 5

    -- How long the retry timeout until a new login can be made (without disabling the ip)
    RetryTimeout = 5000

    -- How long the player need to wait until the ip is allowed again
    LoginTimeout = 60 * 1000

    -- Allow clones (multiple logins of the same char)
    AllowClones = false

    -- Only one player online per account
    CheckAccounts = false

---- DATABASE ----

    -- SQL type
    -- options: mysql, sqlite, odbc or pgsql
    SQL_Type = "sqlite"

    --- SQL connection part
    SQL_DB   = "db.db3"

    -- these settings are not used by SQLite
    SQL_Host = "localhost"
    SQL_Port = 3306
    SQL_User = "root"
    SQL_Pass = ""

---- HOUSES ----

    -- house rent period
    -- options: daily, weekly, monthly
    HouseRentPeriod = "monthly"

    -- Price for a tile
    HousePrice = 100

    HouseLevel = 1
    PremOnlyHouse = true
    PremOnlyBeds = true

--- INFO ---

    -- Login message
    LoginMsg = "Welcome to OTServ. For help visit http://otserv.org"

    -- Server name
    ServerName = "OTServ"

    -- World name
    WorldName = "OpenTibia"

    -- Server owner name
    OwnerName = "Ferrus"

    -- Server owner email
    OwnerEmail = ""

    -- Server url
    URL = ""

    -- Server location
    Location = "Poland"


---- ITEM USAGE ----

    -- Minimum amount of time between actions ('Use') (1000 = 1 second)
    MinActionInterval = 200

    -- Minimum amount of time between extended actions ('Use with...') (1000 = 1 second)
    MinActionExInterval = 1000

---- MAP ----

    -- Map location
    Map = "data/world/Fibula.otbm"

    -- Mapkind
    -- Options: OTBM for binary map, XML for OTX map
    MapKind = "OTBM"

    -- Type of map storage, 
    -- 'relational' - Slower, but possible to run database queries to change all items to another id for example.
    -- 'binary' - Faster, but you cannot run DB queries.
    -- To switch, load server with the current type, change the type in config.lua 
    -- type /reload config and the save the server with /closeserver serversave
    MapStoreType = "binary"

---- RATES ----

    -- Rates (experience, skill, magic level, loot and spawn)
    RateExp = 1
    RateSkill = 1
    RateMag = 1
    RateLoot = 1
    RateSpawn = 1


--- SPAWNS ---

    -- Despawn configs
    -- How many floors can a monster go from his spawn before despawning
    DespawnRange = 2

    -- How many square metters can a monster be far from his spawn before despawning
    DespawnRadius = 50

--- STATUS ---

    -- Message Of The Day box that you sometimes get before you choose characters)
    MOTD = "Welcome to OTServ!"
    MOTD_Num = "1"

    -- Max number of players allowed
    MaxPlayers = "100"

--- OTHER ---

    -- Accounts password type
    -- options: plain, md5, sha1
    PasswordType = "plain"

    -- Max number of messages a player can say before getting muted (default 4), set to 0 to disable muting
    MaxMessageBuffer = 4

    -- Save client debug assertion reports
    SaveClientDebug = false

    -- Should the server use account balance system or depot system for paying houses?
    UseAccBalance = false

    -- Time after player will be kicked when idle, in minutes
    MaxIdleTime = 15

    -- Level on which player will get rooked
    LevelToRook = 5

    -- TownId to which player will be teleported
    RookTempleId = 1

    -- if your website is not showing player deaths, then keep this as false
    StorePlayerDeaths = false

    -- ID of temple to which player will get teleported when his prem end out
    -- 0 to disable
    -- not tested yet
    FACCTempleID = 0

 
