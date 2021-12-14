USE [master]
GO
/****** Object:  Database [PlannerDatabase]    Script Date: 14.12.2021 19:47:51 ******/
CREATE DATABASE [PlannerDatabase]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'PlannerDatabase', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\PlannerDatabase.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'PlannerDatabase_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\PlannerDatabase_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [PlannerDatabase] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [PlannerDatabase].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [PlannerDatabase] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [PlannerDatabase] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [PlannerDatabase] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [PlannerDatabase] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [PlannerDatabase] SET ARITHABORT OFF 
GO
ALTER DATABASE [PlannerDatabase] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [PlannerDatabase] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [PlannerDatabase] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [PlannerDatabase] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [PlannerDatabase] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [PlannerDatabase] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [PlannerDatabase] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [PlannerDatabase] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [PlannerDatabase] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [PlannerDatabase] SET  DISABLE_BROKER 
GO
ALTER DATABASE [PlannerDatabase] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [PlannerDatabase] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [PlannerDatabase] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [PlannerDatabase] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [PlannerDatabase] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [PlannerDatabase] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [PlannerDatabase] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [PlannerDatabase] SET RECOVERY FULL 
GO
ALTER DATABASE [PlannerDatabase] SET  MULTI_USER 
GO
ALTER DATABASE [PlannerDatabase] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [PlannerDatabase] SET DB_CHAINING OFF 
GO
ALTER DATABASE [PlannerDatabase] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [PlannerDatabase] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [PlannerDatabase] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [PlannerDatabase] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
EXEC sys.sp_db_vardecimal_storage_format N'PlannerDatabase', N'ON'
GO
ALTER DATABASE [PlannerDatabase] SET QUERY_STORE = OFF
GO
USE [PlannerDatabase]
GO
/****** Object:  Table [dbo].[Events]    Script Date: 14.12.2021 19:47:51 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Events](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[date] [date] NOT NULL,
	[pick] [nvarchar](50) NOT NULL,
	[category] [nvarchar](50) NOT NULL,
	[userId] [int] NOT NULL,
	[hours] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Events] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Users]    Script Date: 14.12.2021 19:47:51 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Users](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Login] [nvarchar](max) NULL,
	[Password] [nvarchar](max) NULL,
	[FirstName] [nvarchar](max) NULL,
	[LastName] [nvarchar](max) NULL,
	[Email] [nvarchar](max) NULL,
 CONSTRAINT [PK_Users] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Events] ON 

INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1656, CAST(N'2021-11-12' AS Date), N'Bede', N'Cat1', 1, N'do 16:00')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1657, CAST(N'2021-11-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1658, CAST(N'2021-11-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1659, CAST(N'2021-11-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1660, CAST(N'2021-11-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1661, CAST(N'2021-11-19' AS Date), N'Nie bede', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1662, CAST(N'2021-11-28' AS Date), N'Nie wiem', N'Cat5', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1663, CAST(N'2021-11-27' AS Date), N'Nie bede', N'Cat4', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1664, CAST(N'2021-11-26' AS Date), N'Bede', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1665, CAST(N'2021-12-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1666, CAST(N'2021-12-04' AS Date), N'Nie bede', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1667, CAST(N'2021-12-03' AS Date), N'Bede', N'Cat5', 1, N'do 16:00')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1668, CAST(N'2021-12-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1669, CAST(N'2021-12-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1670, CAST(N'2021-12-10' AS Date), N'Nie wiem', N'Cat4', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1671, CAST(N'2021-12-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1672, CAST(N'2021-12-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1673, CAST(N'2021-12-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1674, CAST(N'2021-12-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1675, CAST(N'2021-12-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1676, CAST(N'2021-12-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1677, CAST(N'2022-01-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1678, CAST(N'2022-01-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1679, CAST(N'2021-12-31' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1680, CAST(N'2022-01-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1681, CAST(N'2022-01-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1682, CAST(N'2022-01-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1683, CAST(N'2022-01-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1684, CAST(N'2022-01-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1685, CAST(N'2022-01-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1686, CAST(N'2022-01-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1687, CAST(N'2022-01-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1688, CAST(N'2022-01-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1689, CAST(N'2022-01-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1690, CAST(N'2022-01-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1691, CAST(N'2022-01-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1692, CAST(N'2022-02-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1693, CAST(N'2022-02-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1694, CAST(N'2022-02-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1695, CAST(N'2022-02-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1696, CAST(N'2022-02-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1697, CAST(N'2022-02-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1698, CAST(N'2022-02-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1699, CAST(N'2022-02-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1700, CAST(N'2022-02-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1701, CAST(N'2022-02-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1702, CAST(N'2022-02-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1703, CAST(N'2022-02-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1704, CAST(N'2022-03-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1705, CAST(N'2022-03-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1706, CAST(N'2022-03-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1707, CAST(N'2022-03-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1708, CAST(N'2022-03-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1709, CAST(N'2022-03-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1710, CAST(N'2022-03-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1711, CAST(N'2022-03-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1712, CAST(N'2022-03-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1713, CAST(N'2022-03-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1714, CAST(N'2022-03-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1715, CAST(N'2022-03-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1716, CAST(N'2022-04-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1717, CAST(N'2022-04-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1718, CAST(N'2022-04-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1719, CAST(N'2022-04-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1720, CAST(N'2022-04-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1721, CAST(N'2022-04-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1722, CAST(N'2022-04-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1723, CAST(N'2022-04-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1724, CAST(N'2022-04-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1725, CAST(N'2022-04-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1726, CAST(N'2022-04-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1727, CAST(N'2022-04-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1728, CAST(N'2022-05-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1729, CAST(N'2022-04-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1730, CAST(N'2022-04-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1731, CAST(N'2022-05-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1732, CAST(N'2022-05-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1733, CAST(N'2022-05-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1734, CAST(N'2022-05-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1735, CAST(N'2022-05-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1736, CAST(N'2022-05-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1737, CAST(N'2022-05-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1738, CAST(N'2022-05-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1739, CAST(N'2022-05-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1740, CAST(N'2022-05-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1741, CAST(N'2022-05-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1742, CAST(N'2022-05-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1743, CAST(N'2022-06-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1744, CAST(N'2022-06-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1745, CAST(N'2022-06-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1746, CAST(N'2022-06-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1747, CAST(N'2022-06-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1748, CAST(N'2022-06-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1749, CAST(N'2022-06-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1750, CAST(N'2022-06-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1751, CAST(N'2022-06-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1752, CAST(N'2022-06-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1753, CAST(N'2022-06-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1754, CAST(N'2022-06-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
GO
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1755, CAST(N'2022-07-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1756, CAST(N'2022-07-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1757, CAST(N'2022-07-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1758, CAST(N'2022-07-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1759, CAST(N'2022-07-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1760, CAST(N'2022-07-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1761, CAST(N'2022-07-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1762, CAST(N'2022-07-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1763, CAST(N'2022-07-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1764, CAST(N'2022-07-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1765, CAST(N'2022-07-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1766, CAST(N'2022-07-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1767, CAST(N'2022-07-31' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1768, CAST(N'2022-07-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1769, CAST(N'2022-07-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1770, CAST(N'2022-08-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1771, CAST(N'2022-08-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1772, CAST(N'2022-08-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1773, CAST(N'2022-08-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1774, CAST(N'2022-08-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1775, CAST(N'2022-08-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1776, CAST(N'2022-08-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1777, CAST(N'2022-08-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1778, CAST(N'2022-08-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1779, CAST(N'2022-08-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1780, CAST(N'2022-08-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1781, CAST(N'2022-08-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1782, CAST(N'2022-09-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1783, CAST(N'2022-09-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1784, CAST(N'2022-09-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1785, CAST(N'2022-09-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1786, CAST(N'2022-09-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1787, CAST(N'2022-09-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1788, CAST(N'2022-09-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1789, CAST(N'2022-09-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1790, CAST(N'2022-09-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1791, CAST(N'2022-09-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1792, CAST(N'2022-09-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1793, CAST(N'2022-09-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1794, CAST(N'2022-10-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1795, CAST(N'2022-10-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1796, CAST(N'2022-09-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1797, CAST(N'2022-10-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1798, CAST(N'2022-10-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1799, CAST(N'2022-10-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1800, CAST(N'2022-10-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1801, CAST(N'2022-10-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1802, CAST(N'2022-10-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1803, CAST(N'2022-10-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1804, CAST(N'2022-10-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1805, CAST(N'2022-10-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1806, CAST(N'2022-10-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1807, CAST(N'2022-10-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1808, CAST(N'2022-10-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1809, CAST(N'2022-11-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1810, CAST(N'2022-11-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1811, CAST(N'2022-11-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1812, CAST(N'2022-11-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1813, CAST(N'2022-11-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1814, CAST(N'2022-11-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1815, CAST(N'2022-11-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1816, CAST(N'2022-11-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1817, CAST(N'2022-11-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1818, CAST(N'2022-11-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1819, CAST(N'2022-11-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1820, CAST(N'2022-11-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1821, CAST(N'2022-12-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1822, CAST(N'2022-12-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1823, CAST(N'2022-12-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1824, CAST(N'2022-12-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1825, CAST(N'2022-12-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1826, CAST(N'2022-12-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1827, CAST(N'2022-12-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1828, CAST(N'2022-12-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1829, CAST(N'2022-12-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1830, CAST(N'2022-12-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1831, CAST(N'2022-12-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1832, CAST(N'2022-12-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1833, CAST(N'2023-01-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1834, CAST(N'2022-12-31' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1835, CAST(N'2022-12-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1836, CAST(N'2023-01-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1837, CAST(N'2023-01-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1838, CAST(N'2023-01-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1839, CAST(N'2023-01-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1840, CAST(N'2023-01-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1841, CAST(N'2023-01-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1842, CAST(N'2023-01-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1843, CAST(N'2023-01-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1844, CAST(N'2023-01-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1845, CAST(N'2023-01-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1846, CAST(N'2023-01-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1847, CAST(N'2023-01-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1848, CAST(N'2023-02-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1849, CAST(N'2023-02-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1850, CAST(N'2023-02-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1851, CAST(N'2023-02-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1852, CAST(N'2023-02-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1853, CAST(N'2023-02-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1854, CAST(N'2023-02-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
GO
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1855, CAST(N'2023-02-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1856, CAST(N'2023-02-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1857, CAST(N'2023-02-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1858, CAST(N'2023-02-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1859, CAST(N'2023-02-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1860, CAST(N'2023-03-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1861, CAST(N'2023-03-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1862, CAST(N'2023-03-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1863, CAST(N'2023-03-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1864, CAST(N'2023-03-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1865, CAST(N'2023-03-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1866, CAST(N'2023-03-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1867, CAST(N'2023-03-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1868, CAST(N'2023-03-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1869, CAST(N'2023-03-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1870, CAST(N'2023-03-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1871, CAST(N'2023-03-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1872, CAST(N'2023-04-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1873, CAST(N'2023-04-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1874, CAST(N'2023-03-31' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1875, CAST(N'2023-04-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1876, CAST(N'2023-04-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1877, CAST(N'2023-04-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1878, CAST(N'2023-04-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1879, CAST(N'2023-04-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1880, CAST(N'2023-04-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1881, CAST(N'2023-04-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1882, CAST(N'2023-04-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1883, CAST(N'2023-04-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1884, CAST(N'2023-04-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1885, CAST(N'2023-04-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1886, CAST(N'2023-04-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1887, CAST(N'2023-05-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1888, CAST(N'2023-05-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1889, CAST(N'2023-05-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1890, CAST(N'2023-05-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1891, CAST(N'2023-05-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1892, CAST(N'2023-05-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1893, CAST(N'2023-05-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1894, CAST(N'2023-05-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1895, CAST(N'2023-05-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1896, CAST(N'2023-05-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1897, CAST(N'2023-05-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1898, CAST(N'2023-05-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1899, CAST(N'2023-06-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1900, CAST(N'2023-06-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1901, CAST(N'2023-06-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1902, CAST(N'2023-06-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1903, CAST(N'2023-06-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1904, CAST(N'2023-06-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1905, CAST(N'2023-06-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1906, CAST(N'2023-06-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1907, CAST(N'2023-06-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1908, CAST(N'2023-06-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1909, CAST(N'2023-06-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1910, CAST(N'2023-06-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1911, CAST(N'2023-07-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1912, CAST(N'2023-07-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1913, CAST(N'2023-06-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1914, CAST(N'2023-07-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1915, CAST(N'2023-07-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1916, CAST(N'2023-07-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1917, CAST(N'2023-07-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1918, CAST(N'2023-07-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1919, CAST(N'2023-07-14' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1920, CAST(N'2023-07-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1921, CAST(N'2023-07-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1922, CAST(N'2023-07-21' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1923, CAST(N'2023-07-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1924, CAST(N'2023-07-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1925, CAST(N'2023-07-28' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1926, CAST(N'2023-08-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1927, CAST(N'2023-08-05' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1928, CAST(N'2023-08-04' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1929, CAST(N'2023-08-13' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1930, CAST(N'2023-08-12' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1931, CAST(N'2023-08-11' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1932, CAST(N'2023-08-20' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1933, CAST(N'2023-08-19' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1934, CAST(N'2023-08-18' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1935, CAST(N'2023-08-27' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1936, CAST(N'2023-08-26' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1937, CAST(N'2023-08-25' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1938, CAST(N'2023-09-03' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1939, CAST(N'2023-09-02' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1940, CAST(N'2023-09-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1941, CAST(N'2023-09-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1942, CAST(N'2023-09-09' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1943, CAST(N'2023-09-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1944, CAST(N'2023-09-17' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1945, CAST(N'2023-09-16' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1946, CAST(N'2023-09-15' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1947, CAST(N'2023-09-24' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1948, CAST(N'2023-09-23' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1949, CAST(N'2023-09-22' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1950, CAST(N'2023-10-01' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1951, CAST(N'2023-09-30' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1952, CAST(N'2023-09-29' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1953, CAST(N'2023-10-08' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1954, CAST(N'2023-10-07' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
GO
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1955, CAST(N'2023-10-06' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1958, CAST(N'2021-11-12' AS Date), N'Nie bede', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1959, CAST(N'2021-12-03' AS Date), N'Nie bede', N'Cat1', 1, N'Caly dzien')
INSERT [dbo].[Events] ([id], [date], [pick], [category], [userId], [hours]) VALUES (1960, CAST(N'2021-12-10' AS Date), N'Nie wiem', N'Cat1', 1, N'Caly dzien')
SET IDENTITY_INSERT [dbo].[Events] OFF
GO
SET IDENTITY_INSERT [dbo].[Users] ON 

INSERT [dbo].[Users] ([ID], [Login], [Password], [FirstName], [LastName], [Email]) VALUES (1, N'bartis30', N'pomidor24', N'Bartlomiej ', N'Sawicki', N'bartis300@gmail.com')
SET IDENTITY_INSERT [dbo].[Users] OFF
GO
ALTER TABLE [dbo].[Events]  WITH CHECK ADD  CONSTRAINT [FK_Events_Users] FOREIGN KEY([userId])
REFERENCES [dbo].[Users] ([ID])
GO
ALTER TABLE [dbo].[Events] CHECK CONSTRAINT [FK_Events_Users]
GO
USE [master]
GO
ALTER DATABASE [PlannerDatabase] SET  READ_WRITE 
GO
