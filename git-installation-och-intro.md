# Git på Windows med UCRT64 och GitHub

Välj ett av två spår: SSH i kursens UCRT64-terminal, eller HTTPS med webbläsarinloggning. Du behöver **inte** konfigurera båda.

Något som kan vara både för- och nackdel är att det finns många sätt att göra detta på. **Jag** kommer använda git i UCRT64-terminalen, **ni** kan som sagt välja om ni föredrar något mer grafiskt - inklusive att köra det via VS Code:s inbyggda stöd (som bara kräver att git i *någon* form är installerat).

Längst ner i dokumentet ligger [Enkla Git-kommandon för kursen](#enkla-git-kommandon-för-kursen)

---

Git sparar projektets ändringshistorik lokalt. GitHub är tjänsten där vi delar repositorier. Kursrepot ligger på https://github.com/joakim-systementor/CppForDevelopers. **Gör en egen fork av kursrepot innan du klonar det.** En fork är en kopia av repot på ditt eget GitHub-konto, med en koppling till lärarens original. Du kan då skapa branches, ändra exemplen och pusha ditt arbete till din egen kopia utan att behöva skrivrättighet i lärarens repo eller påverka andra studenters kursmaterial. Kopplingen till originalet gör att du också kan hämta nya exempel och rättningar under kursen. Du behöver ingen inloggning för lokala commits; autentisering behövs när du skickar ändringar till din fork.

Om ni väljer att antingen inte lägga upp något på er egen GitHub eller om ni vill ladda ner filerna från mitt repo och sen skapa ett nytt eget repo där ni börjar helt från scratch så kan ni klona mitt repo direkt genom:

* https://github.com/joakim-systementor/CppForDevelopers.git - om ni kör med HTTPS
* [git@github.com:joakim-systementor/CppForDevelopers.git](git@github.com:joakim-systementor/CppForDevelopers.git) - om ni kör med SSH
* Det kan klonas ner med ```gh repo clone joakim-systementor/CppForDevelopers``` om ni kör med GitHub CLI

### Skapa din fork på GitHub

Öppna [lärarens kursrepo](https://github.com/joakim-systementor/CppForDevelopers), logga in och välj **Fork**. Välj ditt eget konto som ägare och skapa kopian. Klona sedan din fork till datorn med adressen från den gröna knappen som säger **Code**, till exempel:

* HTTPS: `https://github.com/DITT_KONTO/CppForDevelopers.git`
* SSH: `git@github.com:DITT_KONTO/CppForDevelopers.git`

Fork skapar kopian på GitHub; clone laddar ned en lokal kopia att arbeta i. När du klonar din fork blir origin din egen kopia, så push går till ditt konto. Ha gärna main som kursens grundmaterial och gör egna övningar i separata branches. [GitHub: skapa en fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo).

## Installera Git i UCRT64

Öppna **MSYS2 UCRT64**. Uppdatera MSYS2 enligt [MSYS2:s installationsguide](https://www.msys2.org/); om uppdateringen kräver omstart av terminalen, gör det innan paket installeras.

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-git openssh

git --version
ssh -V
type -a git ssh ssh-keygen ssh-agent ssh-add
```

Git-paketet ovan är MSYS2:s Windows-version för UCRT64. OpenSSH-paketet tillhandahåller SSH-klient och nyckelverktyg. Dag 1:s installation innehåller ännu inte dessa Git-/SSH-paket, så detta är ett tillägg till den miljö du redan har installerat. Kontrollera att Git väljs från `/ucrt64/bin` och att SSH-verktygen i detta spår kommer från `/usr/bin`. [MSYS2: Git](https://www.msys2.org/docs/git/), [Git-paketet](https://packages.msys2.org/packages/mingw-w64-ucrt-x86_64-git), [OpenSSH-paketet](https://packages.msys2.org/packages/openssh).

### Vi använder PATH-inställningen från dag 1

I dag 1:s PowerPoint lägger vi redan till följande mappar i Windows PATH:

* `C:\msys64\ucrt64\bin` för bland annat kompilatorn och senare Git
* `C:\msys64\usr\bin` för bland annat Make och senare OpenSSH-verktygen

Behåll detta upplägg. Du behöver inte lägga till mapparna igen för Git. Efter installationen kan verktygen också hittas i PowerShell och cmd via dessa PATH-poster. Öppna en ny terminal, och starta om VS Code om det var öppet när PATH ändrades.

Kontrollera i PowerShell eller cmd:

```powershell
where.exe git
where.exe ssh
where.exe ssh-keygen
where.exe ssh-agent
where.exe make
```

För kursens spår ska första träffen för Git vara `C:\msys64\ucrt64\bin\git.exe`, och SSH-verktygen ska komma från `C:\msys64\usr\bin`. Anpassa sökvägarna om MSYS2 installerats på annan plats. `where.exe` kan visa flera installationer; i PowerShell använder vi uttryckligen `.exe` eftersom `where` även är ett alias. PowerShell kan dessutom ha egna alias eller funktioner; kontrollera vid behov med `Get-Command git, ssh -All`.

Git Bash och UCRT64 är separata miljöer även om båda använder Bash. Windows PATH gör programmen tillgängliga, men gör inte automatiskt hemkataloger, Git-inställningar och SSH-agenter gemensamma. SSH-stegen nedan genomförs därför i UCRT64. Bash-kommandot `eval` ska inte klistras in direkt i PowerShell.

## Ange namn och e-post för commits

```sh
git config --global user.name "Ditt Namn"
git config --global user.email "din-adress@example.com"
git config --global init.defaultBranch main

git config --global --get user.name
git config --global --get user.email
```

E-postadressen hör till commitens författaruppgifter och är inget lösenord. Använd din verifierade GitHub-adress eller kontots noreply-adress om du vill dölja den vanliga adressen. Kopiera noreply-adressen från GitHub under **Settings > Emails**. `--global` gäller den Git-användarmiljö du kör i; kontrollera inställningen igen om du byter miljö. [GitHub: commit-e-post](https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-email-preferences/setting-your-commit-email-address).

## Filnamn och radslut på Windows

Kör följande i UCRT64, PowerShell eller Git Bash med den Git-installation du använder:

```sh
git config --global core.quotePath false
git config --global core.autocrlf true
```

### Visa svenska tecken med quotePath

`core.quotePath false` gör att Git visar exempelvis `Övningar.md` i stället för `"\303\226vningar.md"` i utskrifter som `git status`. Inställningen ändrar bara visningen, inte filnamnet eller filens innehåll. Namn med exempelvis blanksteg kan fortfarande visas inom citationstecken.

Detta är användbart i vår Windows-miljö, men kan även behövas på Linux/macOS eftersom Git också där kan visa svenska tecken som escape-sekvenser. Inställningen är alltså inte begränsad till Windows.

### Hantera radslut med autocrlf

`core.autocrlf true` är Windows-inställningen för LF-radslut i Git och CRLF-radslut i arbetskopians textfiler:

* Vid `git add` normaliseras textfilernas CRLF till LF
* Vid checkout skrivs normaliserade textfiler med CRLF i arbetskopian

På Linux/macOS används normalt LF även i arbetskopian, så där bör du inte kopiera inställningen `autocrlf true` från Windows-spåret. Regler i repots `.gitattributes` kan styra radsluten för enskilda filer och har företräde framför denna standardinställning.

Inställningen skriver inte om alla befintliga filer direkt när kommandot körs. I VS Code ser du den öppna filens `LF` eller `CRLF` nere till höger i statusfältet; du kan klicka där för att ändra och spara om du vill ändra för en specifik fil.

### Kontrollera inställningarna

```sh
git config --show-origin --get core.quotePath
git config --show-origin --get core.autocrlf
```

För detta Windows-spår ska värdena vara `false` respektive `true`. `--show-origin` visar också vilken konfigurationsfil värdet kommer från. `--global` gäller alla repositorier som använder den användarkonfigurationen. Vill du bara ändra ett repo, kör kommandona inne i repot med `--local` i stället.

[Git-dokumentation: konfigurationsinställningar](https://git-scm.com/docs/git-config), [Regler för radslut i .gitattributes](https://git-scm.com/docs/gitattributes).

## SSH - skapa och registrera en nyckel

### Kontrollera hemkatalog och befintliga nycklar

```sh
printf '%s\n' "$HOME"
ls -la ~/.ssh
```

Om `.ssh` inte finns är det normalt vid första användningen. MSYS2:s hemkatalog kan vara en annan än hemkatalogen i Git Bash eller Windows OpenSSH. Använd samma miljö genom hela SSH-spåret.

### Skapa nyckelparet

Byt e-postadressen och kör:

```sh
ssh-keygen -t ed25519 -C "din-adress@example.com"
```

Acceptera standardnamnet om det är ledigt. Finns redan en nyckel: skriv inte över den; återanvänd rätt nyckel eller välj ett annat filnamn och använd det namnet i kommandona nedan. Ange gärna en lösenfras för den privata nyckeln.

* `~/.ssh/id_ed25519` är den privata nyckeln och ska stanna på din dator
* `~/.ssh/id_ed25519.pub` är den publika nyckeln som du lägger till på GitHub

Lägg aldrig den privata nyckeln i ett repo, en inlämning eller ett meddelande. [GitHub: skapa SSH-nyckel](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent).

### Lägg den publika nyckeln på GitHub

Visa filen:

```sh
cat ~/.ssh/id_ed25519.pub
```

Kopiera hela raden, från `ssh-ed25519` till slutet. På GitHub: **Settings > SSH and GPG keys > New SSH key**. Ge den ett beskrivande namn, välj **Authentication Key** och klistra in den publika nyckeln. [GitHub: registrera SSH-nyckel](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account).

### Använd ssh-agent för lösenfrasen

Kör i samma UCRT64-terminal som du ska använda för Git:

```sh
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
ssh-add -l
```

Agenten kan komma ihåg den upplåsta nyckeln under arbetet. Dessa kommandon startar ingen permanent Windows-tjänst. `eval` sätter agentens miljövariabler i den aktuella Bash-terminalen; en separat öppnad PowerShell-terminal får dem inte automatiskt bara för att SSH finns i PATH. Använd samma UCRT64-terminal för agent, anslutningstest och Git. I en ny terminal kan du behöva starta en agent och lägga till nyckeln igen. SSH kan även använda en standardnyckel utan agent och då fråga efter lösenfrasen när den behövs. Lägg inte en ny agentstart i varje terminalstart utan att hantera återanvändning och avslut. När den agent du startade inte längre behövs kan den avslutas med `ssh-agent -k`. [GitHub: nyckel och agent](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent).

### Kontrollera anslutningen

```sh
ssh -T git@github.com
```

Första gången visas serverns fingeravtryck. Jämför med [GitHubs publicerade SSH-fingeravtryck](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/githubs-ssh-key-fingerprints) innan du accepterar.

En lyckad autentisering ger ett meddelande med ditt GitHub-användarnamn och text om att GitHub inte ger shell-åtkomst. Just detta kontrollkommando kan returnera status 1 även när autentiseringen lyckats; läs meddelandet. [GitHub: testa SSH](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/testing-your-ssh-connection).

## Klona och öppna kursmaterialet

Byt adressen nedan till din egen fork, med ditt GitHub-konto som ägare. `git` i SSH-adressen är alltid användaren `git`, inte ditt GitHub-användarnamn.

```sh
cd /c/Users/DITT_WINDOWS_NAMN/Documents
git clone git@github.com:AGARE/KURSREPO.git
cd KURSREPO

git remote -v
git status
```

På Windows skrivs en C:-sökväg som `/c/...` i UCRT64. Om mappen har blanksteg, sätt citationstecken runt sökvägen. Öppna den klonade mappen i VS Code via **File > Open Folder**.

Kursens exempel ligger direkt i dagsmapparna. Kör till exempel från dag 3:

```sh
cd dag_3
cmake -S . -B build -G Ninja
cmake --build build
```

När du klonar din egen fork kan du pusha dina commits till den. Du får fortfarande inte automatiskt skrivrättighet i lärarens original. Kontrollera med git remote -v att origin pekar på ditt konto och gör egna övningar på en egen branch.

För att hämta nytt material från läraren: öppna först din fork på GitHub och välj **Sync fork > Update branch** för main. Byt sedan till din lokala main och hämta uppdateringen när arbetskopian inte har egna ocommittade ändringar:

```sh
git switch main
git status
git pull --ff-only
```

Pull hämtar från din fork, inte direkt från lärarens original. [GitHub: synkronisera en fork](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/syncing-a-fork).

Om pull stoppas av egna ändringar eller olika historik: be om hjälp innan du raderar eller skriver över något. `--ff-only` skapar ingen oväntad merge-commit.

## Alternativ - HTTPS och webbläsarinloggning

### Git for Windows och Git Credential Manager

[Git for Windows](https://gitforwindows.org/) kan användas från PowerShell, cmd, Git Bash och VS Codes terminal. Installera med Git Credential Manager och använd en HTTPS-adress. Med kursens PATH kan kommandot `git` fortfarande välja MSYS2:s Git. Kontrollera med `where.exe git` innan du använder detta alternativ.

I PowerShell kan du välja Git for Windows uttryckligen utan att ändra kursens PATH:

```powershell
& "C:\Program Files\Git\cmd\git.exe" --version
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/AGARE/KURSREPO.git
```

Anpassa installationssökvägen om den skiljer sig. `&` är PowerShells anropsoperator för en programsökväg inom citationstecken. I Git Bash kan du i stället använda `git clone https://github.com/AGARE/KURSREPO.git` efter att ha kontrollerat `type -a git`.

Ett publikt repo kräver normalt ingen inloggning för kloning. Vid en åtgärd som behöver autentisering hjälper Git Credential Manager till med webbläsarinloggning. Ange inte kontots vanliga lösenord som Git-lösenord; GitHub stöder inte sådan lösenordsautentisering för Git över HTTPS. [GitHub: hantera Git-inloggning](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git).

Detta är en separat installation från MSYS2:s Git-paket. Att Credential Manager finns för Git for Windows betyder inte automatiskt att MSYS2:s Git använder det; valet beror på den aktuella Git-konfigurationen och vilka hjälpprogram den hittar. Använd Git for Windows för detta beskrivna alternativ, eller GitHub CLI-alternativet nedan för MSYS2:s Git.

### GitHub CLI i UCRT64

Ett alternativ utan egen SSH-nyckel är GitHub CLI och HTTPS. Installera `gh`:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-github-cli
gh auth login --hostname github.com --git-protocol https --web
gh auth setup-git
gh auth status
```

Följ webbläsarinloggningen. `setup-git` gör GitHub CLI till credential helper för Git. Det ersätter inte Git självt och ändrar inte redan klonade repositoriers remote-adresser. [GitHub CLI: login](https://cli.github.com/manual/gh_auth_login), [setup-git](https://cli.github.com/manual/gh_auth_setup-git), [MSYS2-paketet](https://packages.msys2.org/packages/mingw-w64-ucrt-x86_64-github-cli).

### Byta adress för ett redan klonat repo

Kontrollera först med `git remote -v`. Välj sedan ett av alternativen:

```sh
# SSH
git remote set-url origin git@github.com:AGARE/KURSREPO.git

# HTTPS
git remote set-url origin https://github.com/AGARE/KURSREPO.git
```

Remote-adressen avgör vilket autentiseringsspår som används. Att lägga till en SSH-nyckel ändrar inte en befintlig HTTPS-adress.

## Ett litet arbetsflöde i ditt eget repo

Kör detta i ett eget övningsprojekt, inte i lärarens repo:

```sh
git init
git status
git add main.cpp CMakeLists.txt .gitignore
git diff --staged
git commit -m "Lägg till första körbara exemplet"
git log --oneline
```

`add` väljer vad nästa commit ska innehålla. `commit` sparar historiken lokalt; det skickar inget till GitHub. Skapa ett eget repo på GitHub om du också vill lagra det där. Om du ska pusha ett redan befintligt lokalt repo, skapa GitHub-repot tomt utan separat README, licens eller gitignore och använd dess faktiska adress:

```sh
git remote add origin git@github.com:DITT_KONTO/MITT_REPO.git
git push -u origin main
```

Använd HTTPS-adressen i stället om du valt HTTPS-spåret. Ditt repo ska ha `.gitignore` för build-mappar och lokala filer innan du använder `git add`.

## Vanliga problem

| Problem | Kontroll och åtgärd |
|---|---|
| git eller ssh hittas inte | Kontrollera terminalen, installationen och `type -a git ssh` |
| Permission denied (publickey) | Kontrollera rätt konto, att den publika nyckeln finns på GitHub, `ssh-add -l` och vilken SSH-klient du använder |
| SSH-testet fungerar men Git misslyckas | Kontrollera `git remote -v`, `git config --show-origin --get core.sshCommand` och eventuella `GIT_SSH`/`GIT_SSH_COMMAND`-inställningar |
| Olika klienter hittar olika nycklar | Jämför hemkataloger och SSH-klienter; PATH-inställningen delar inte automatiskt nyckelmappar eller agentens miljövariabler |
| Fel Git eller SSH startas från PowerShell | Kontrollera `where.exe git`, `where.exe ssh` och `Get-Command git, ssh -All`; välj avsedd installation uttryckligen vid behov |
| Git frågar efter lösenord via HTTPS | Använd webbläsarinloggning med Credential Manager eller GitHub CLI, inte GitHub-kontots lösenord |
| Åtkomst nekas vid push | Kloning ger inte skrivrättighet; använd ditt eget repo eller tilldelad behörighet |

Vid klientkonflikt kan ett repo uttryckligen använda MSYS2:s SSH. Följande är en lokal inställning för just repot och förutsätter standardinstallationen `C:\msys64`:

```sh
git config --local core.sshCommand C:/msys64/usr/bin/ssh.exe
```

Anpassa sökvägen om MSYS2 ligger någon annanstans. Detta kommando ska bara användas om du behöver välja klient uttryckligen; använd samma MSYS2-agent och nycklar som ovan. Vill du ta bort just denna lokala inställning, kör `git config --local --unset core.sshCommand`.

## Andra sätt att arbeta med Git på Windows

| Verktyg eller miljö | Passar för |
|---|---|
| [PowerShell eller cmd med Git for Windows](https://gitforwindows.org/) | Vanliga Git-kommandon utan Bash |
| [VS Code Source Control](https://code.visualstudio.com/docs/sourcecontrol/overview) | Granska diffar, stage, commit och synkronisera i editorn; kräver installerad Git |
| [GitHub Desktop](https://github.com/apps/desktop) | En enkel grafisk GitHub-klient |
| [Sourcetree](https://www.sourcetreeapp.com/) | Grafisk hantering av branches, historik och merges |
| [GitKraken Desktop](https://www.gitkraken.com/git-client) | Visuell historik och brancharbete |
| [TortoiseGit](https://tortoisegit.org/) | Git-kommandon via Utforskarens snabbmenyer |
| [WSL med Linux-Git](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-git) | Linux-miljö på Windows; separat från kursens UCRT64-miljö |

Windows Terminal är ett terminalfönster som kan samla profiler för exempelvis PowerShell, UCRT64 och WSL. Det är ingen Git-klient eller installation av Git i sig. För kursen räcker UCRT64; VS Codes Git-vy kan användas som visuellt stöd.

## Enkla Git-kommandon för kursen

Kör kommandona inne i ditt repo. Exemplen med egna commits och push förutsätter ett eget repo eller ett repo där du har skrivrättighet. `origin` är namnet som en vanlig kloning ger fjärrrepot; kontrollera adressen med `git remote -v`.

### Kontrollera vad du arbetar med

```sh
git status
git branch
```

`status` visar aktuell branch, ändrade filer och vilka ändringar som är staged, alltså valda för nästa commit. `branch` listar lokala branches; en asterisk markerar den aktuella. En branch är ett namn på en utvecklingslinje i historiken, inte en separat mapp.

### Skapa en branch och byt till den

```sh
git switch main
git pull --ff-only
git switch -c ovning-dag-3
```

`switch -c` skapar en ny lokal branch från den commit du står på och byter till den. Här börjar övningsbranchen från en uppdaterad main. Välj ett beskrivande namn utan blanksteg. Om namnet redan finns, använd `switch` utan `-c`.

```sh
git switch main
git switch ovning-dag-3
```

Dessa två kommandon visar hur du byter mellan befintliga lokala branches. Kontrollera först `git status` och spara färdigt arbete i en commit. Git kan tillåta byte med ofärdiga ändringar, men kan också stoppa bytet om ändringar skulle skrivas över. Ett branchbyte sparar inte ändringarna som en commit. [Git: switch](https://git-scm.com/docs/git-switch).

### Välj ändringar med add och spara med commit

```sh
git status
git add dag_3/main.cpp dag_3/sensor.cpp dag_3/sensor.hpp
git diff --staged
git commit -m "Dela upp sensorlogiken i egna filer"
```

`add` väljer filernas aktuella ändringar för nästa commit. Ändrar du filen igen efter add, behöver du köra add igen för att den nya ändringen ska ingå. `diff --staged` visar vad du har valt. `commit` sparar en lokal ögonblicksbild med ett meddelande som beskriver förändringen.

Du kan också använda `git add .` för ändringar under den aktuella mappen. Använd det när du har kontrollerat status och har en lämplig .gitignore, så att du inte råkar ta med orelaterade filer. Add och commit skickar inget till GitHub. Push skickar commits, inte ändringar som bara är sparade i editorn eller staged. [Git: add](https://git-scm.com/docs/git-add), [Git: commit](https://git-scm.com/docs/git-commit).

### Skicka din branch med push

Första gången du skickar din nya branch:

```sh
git push -u origin ovning-dag-3
```

Det skickar branchens commits till origin och kopplar den lokala branchen till origin/ovning-dag-3 som upstream, alltså den fjärrbranch Git normalt ska använda för denna lokala branch.

Efter nya add och commit kan du normalt köra:

```sh
git push
```

Push sammanfogar inte automatiskt övningsbranchen med main. Om push nekas för att fjärrbranchen har nya commits behöver du först hämta och hantera dem; använd inte force-push som rutinlösning. [Git: push](https://git-scm.com/docs/git-push).

### Hämta uppdateringar med pull

```sh
git status
git pull --ff-only
```

Pull hämtar fjärrhistoriken och försöker uppdatera den branch du står på från dess upstream. Det uppdaterar inte alla lokala branches på en gång. `--ff-only` tillåter bara en uppdatering där din branch kan flyttas framåt i samma historik, utan en ny merge-commit.

Om både du och någon annan har skapat egna commits efter den gemensamma utgångspunkten stannar kommandot. Då behöver ni välja hur historiken ska sammanfogas; fråga läraren i stället för att kasta bort commits. Kontrollera också ocommittade ändringar före pull. [Git: pull](https://git-scm.com/docs/git-pull).

### Lista branches på origin

```sh
git fetch origin --prune
git branch -r --list "origin/*"
```

Fetch hämtar information om origin utan att byta branch eller sammanfoga något i dina arbetsfiler. `--prune` tar bort inaktuella lokala fjärrreferenser för branches som raderats på origin; det raderar inte dina egna lokala branches.

`branch -r` visar fjärrreferenser som din dator känner till, till exempel origin/main och origin/ovning-dag-3. Därför kör vi fetch först. En rad som origin/HEAD -> origin/main anger origin:s standardbranch och är inte en extra övningsbranch.

För att fråga servern direkt utan att uppdatera dina lokala referenser:

```sh
git ls-remote --heads origin
```

Det visar commit-id och branchreferenser som finns på origin vid förfrågan. [Git: fetch](https://git-scm.com/docs/git-fetch), [Git: branch](https://git-scm.com/docs/git-branch), [Git: ls-remote](https://git-scm.com/docs/git-ls-remote).

### Börja arbeta på en branch som redan finns på origin

Om origin/ovning-dag-4 finns men du ännu inte har någon lokal branch med det namnet:

```sh
git fetch origin
git switch -c ovning-dag-4 --track origin/ovning-dag-4
```

Det skapar en lokal branch som följer fjärrbranchen och byter till den. Finns den lokala branchen redan, använd bara `git switch ovning-dag-4`. Arbeta på den lokala branchen; origin/ovning-dag-4 är en fjärrreferens som uppdateras vid kontakt med origin.

### Ett vanligt arbetspass

När din lokala övningsbranch redan har skapats och har en upstream:

```sh
git switch ovning-dag-3
git status
git pull --ff-only

# Arbeta med koden och kontrollera att den fungerar.

git add dag_3/main.cpp
git diff --staged
git commit -m "Hantera felaktiga sensorvärden"
git push
```

Anpassa filnamn och commit-meddelande till din verkliga ändring. Du behöver inte skapa en ny branch eller göra en commit om inget har ändrats.

## Fler användbara Git-kommandon

Dessa kommandon hjälper dig att granska, lägga undan och sammanfoga arbete. Kör dem i rätt repo och kontrollera den aktuella branchen med `git status`.

### Diff - se vad som har ändrats

```sh
git diff
git diff --staged
```

`git diff` jämför arbetskopians spårade filer med staging. Det visar alltså ändringar som ännu inte valts med add. `git diff --staged` jämför staging med den senaste committen och visar innehållet i nästa commit.

Efter add kan du fortsätta redigera filen. Då kan samma fil ha både staged och unstaged ändringar, och de två kommandona visar olika delar. Nya ospårade filer visas i status, men deras innehåll visas inte av vanlig diff innan de har lagts till.

```sh
git diff -- dag_3/main.cpp
git diff --staged -- dag_3/main.cpp
```

Här begränsas jämförelsen till en fil. `--` skiljer filnamnen från kommandots övriga argument. I en vanlig textdiff betyder `-` borttagna rader och `+` tillagda rader. Kommandona ändrar inget i filerna. [Git: diff](https://git-scm.com/docs/git-diff).

### Log - förstå historiken

```sh
git log --oneline --graph --all
```

* `--oneline` visar kort commit-id och meddelande på en rad
* `--graph` ritar hur utvecklingslinjerna hänger ihop
* `--all` tar med commits som nås från alla lokalt kända referenser, även fjärrreferenser

Log hämtar inget från GitHub. Kör fetch först om du behöver aktuell fjärrhistorik. Kopiera ett commit-id ur loggen när du vill granska eller upphäva just den ändringen. Begränsa vid behov utskriften med `git log --oneline -5`. Om utskriften öppnas i en pager som less, avsluta med `q`. [Git: log](https://git-scm.com/docs/git-log).

### Restore --staged - ändra vad nästa commit ska innehålla

```sh
git add dag_3/main.cpp
git restore --staged dag_3/main.cpp
git status
```

Det andra kommandot återställer filens staging till den senaste committen. Dina ändringar i arbetskopian finns kvar och kan läggas till senare. För en helt ny fil blir den åter ospårad. Det är användbart om du råkat välja fel fil eller vill dela arbetet i flera commits.

`--staged` är avgörande: `git restore FIL` utan den flaggan återställer i stället arbetsfilen från staging och kan kasta bort unstaged ändringar. Inget av alternativen ändrar redan skapade commits. [Git: restore](https://git-scm.com/docs/git-restore).

### Stash - lägg undan ofärdigt arbete

Anta att du har påbörjat en ändring men behöver byta branch innan den är redo för commit:

```sh
git status
git stash push -u -m "Ofärdig sensorövning"
git switch main
```

Stash sparar staged och unstaged ändringar lokalt och återställer de undanlagda delarna i arbetskopian. `-u` tar även med nya ospårade filer, men inte ignorerade filer som build-resultat. Stash skickas inte till GitHub med vanlig push.

När du vill fortsätta:

```sh
git switch ovning-dag-3
git stash list
git stash pop
git status
```

Pop återför den senaste stashen på den branch du nu står på och tar bort stash-posten om återföringen lyckas. Utan en extra flagga återställs inte automatiskt den tidigare uppdelningen i staging; kontrollera status och välj ändringarna med add igen.

Återföringen kan ge konflikter om samma rader har ändrats. Då behålls stash-posten, men arbetskopian kan redan ha fått vissa ändringar. Lös konflikten innan du försöker pop igen. `git stash apply` återför också ändringarna men behåller posten även när det lyckas, vilket kan vara bra när du vill kontrollera resultatet först. [Git: stash](https://git-scm.com/docs/git-stash).

### Show - granska en viss commit

```sh
git show HEAD
git show --stat HEAD
```

HEAD är normalt den senaste committen på din aktuella branch. Show visar dess meddelande och ändringar; `--stat` ger en kort översikt över berörda filer och radantal. Byt HEAD mot ett commit-id från loggen för att granska en äldre commit. Show ändrar varken branch eller arbetsfiler. [Git: show](https://git-scm.com/docs/git-show).

### Merge - sammanfoga en branch

För att ta in en färdig övningsbranch i din lokala main:

```sh
git switch main
git status
git pull --ff-only
git merge ovning-dag-3
```

Det är den aktuella branchen som uppdateras. Övningsbranchen finns kvar. Om historiken är en rak fortsättning kan main flyttas fram utan en extra commit. Om brancherna har utvecklats åt olika håll kan Git skapa en merge-commit.

Har båda brancherna ändrat samma område kan Git behöva din hjälp. Status visar konfliktfilerna; redigera dem till det resultat som ska behållas, ta bort konfliktmarkeringarna och kontrollera att koden fungerar. Välj sedan de lösta filerna med add och avsluta med `git commit`.

Vill du avbryta en pågående konfliktfylld merge kan du använda `git merge --abort`. Börja därför med sparat arbete och en ren arbetskopia, så att ditt tidigare arbete inte blandas ihop med konflikten.

När sammanfogningen är klar skickar du main med `git push`. Vid samarbete kan samma sammanfogning i stället hanteras med en pull request på GitHub. [Git: merge](https://git-scm.com/docs/git-merge).

### Revert - upphäv en commit med en ny commit

Revert fungerar även på commits som redan har pushats till GitHub. Den ursprungliga committen finns kvar i historiken; Git skapar en ny commit med motsatt ändring. Det gör revert lämpligt när andra redan kan ha hämtat historiken.

För att upphäva den senaste vanliga committen på aktuell branch:

```sh
git status
git log --oneline -5
git revert HEAD
```

Börja med en ren arbetskopia. Byt HEAD mot det verkliga commit-id:t om det gäller en äldre commit. Git kan öppna din konfigurerade editor för meddelandet; spara och avsluta för att färdigställa committen. Kontrollera sedan resultatet och koden. Om branchen följer rätt fjärrbranch skickar du den nya revert-committen med vanlig `git push`.

Om den upphävda committen redan finns på GitHub ligger den alltså fortfarande kvar där, tillsammans med den nya commit som upphäver den. Historiken behöver inte skrivas om. Det skiljer sig från reset eller rebase som kan flytta eller ändra befintlig historik.

Revert av en äldre commit kan ge konflikter med senare ändringar. Lös filerna, lägg till dem med add och fortsätt med `git revert --continue`, eller avbryt försöket med `git revert --abort`. Välj ett av dessa alternativ, inte båda. Revert av en merge-commit kräver ett särskilt val av huvudlinje och ingår inte i detta grundexempel. [Git: revert](https://git-scm.com/docs/git-revert).
