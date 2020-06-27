-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 27, 2020 at 09:02 AM
-- Server version: 10.4.11-MariaDB
-- PHP Version: 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `javaprojdb`
--

-- --------------------------------------------------------

--
-- Table structure for table `tblbills`
--

CREATE TABLE `tblbills` (
  `billID` int(11) NOT NULL,
  `employeeId` int(11) NOT NULL,
  `month` varchar(25) NOT NULL,
  `yr` int(11) NOT NULL,
  `totAll` double NOT NULL,
  `totDed` double NOT NULL,
  `gross` double NOT NULL,
  `net` double NOT NULL,
  `account` mediumint(9) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tblbills`
--

INSERT INTO `tblbills` (`billID`, `employeeId`, `month`, `yr`, `totAll`, `totDed`, `gross`, `net`, `account`) VALUES
(1, 2, 'January', 2020, 2300, 3150, 12300, 9150, 1200121),
(2, 3, 'June', 2020, 345, 472.5, 1845, 1372.5, 7885441),
(3, 8, 'June', 2020, 2300, 3150, 12300, 9150, 102250);

-- --------------------------------------------------------

--
-- Table structure for table `tbldepts`
--

CREATE TABLE `tbldepts` (
  `deptID` varchar(10) NOT NULL,
  `department` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tbldepts`
--

INSERT INTO `tbldepts` (`deptID`, `department`) VALUES
('dpt001', 'Adminstration');

-- --------------------------------------------------------

--
-- Table structure for table `tblemployees`
--

CREATE TABLE `tblemployees` (
  `employeeId` int(11) NOT NULL,
  `name` varchar(25) NOT NULL,
  `surname` varchar(25) NOT NULL,
  `nationalID` varchar(15) NOT NULL,
  `gender` varchar(1) NOT NULL CHECK (`gender` in ('M','F')),
  `dob` date DEFAULT NULL,
  `phoneNumber` int(11) NOT NULL,
  `email` varchar(30) NOT NULL,
  `homeAddress` varchar(50) NOT NULL,
  `department` varchar(35) NOT NULL,
  `grade` varchar(10) NOT NULL,
  `salary` int(11) NOT NULL,
  `accountNo` mediumint(9) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tblemployees`
--

INSERT INTO `tblemployees` (`employeeId`, `name`, `surname`, `nationalID`, `gender`, `dob`, `phoneNumber`, `email`, `homeAddress`, `department`, `grade`, `salary`, `accountNo`) VALUES
(2, 'ellis', 'mapakam', '1223', 'M', '1998-05-06', 777612441, 'ellis@ellis.com', 'jakarta', 'Adminstration', 'Grade A', 10000, 1200121),
(3, 'floyd', 'mapax', '120012', 'M', '1991-09-09', 778145, 'floyd@floyd.gov', 'Bindura', 'Accounts', 'Grade B', 1500, 7885441),
(7, 'qwerty', 'qwert', '124678', 'F', '1998-01-04', 81451312, 'email@email', 'new york', 'IT', 'Grade C', 1200, 10201),
(8, 'New', 'Employee', '1200011', 'F', '1999-01-01', 81211000, 'employeenew@yahoo.com', 'Jakarta', 'Legal', 'Grade A', 10000, 102250);

-- --------------------------------------------------------

--
-- Table structure for table `tblleave`
--

CREATE TABLE `tblleave` (
  `ID` int(11) NOT NULL,
  `employeeId` int(11) NOT NULL,
  `sdate` date DEFAULT NULL,
  `edate` date DEFAULT NULL,
  `reason` varchar(200) NOT NULL,
  `approved` smallint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tblleave`
--

INSERT INTO `tblleave` (`ID`, `employeeId`, `sdate`, `edate`, `reason`, `approved`) VALUES
(1, 3, '2020-06-27', '2020-07-01', 'Doctors Appointment', 1),
(2, 3, '2020-06-04', '2020-06-04', 'mmm', 1),
(3, 3, '2020-06-10', '2020-06-10', 'aa', 1),
(4, 3, '2020-06-28', '2020-06-28', 'dxbdgbd', 1),
(5, 3, '2020-06-17', '2020-06-17', 'hhhh', 1),
(6, 3, '2020-06-18', '2020-06-18', 'zaa', 1),
(7, 3, '2020-06-03', '2020-06-03', 'x', 1),
(8, 3, '2020-06-18', '2020-06-18', 'aa', 1),
(9, 3, '2020-06-19', '2020-06-19', 'ccc', 1),
(10, 7, '2020-06-28', '2020-06-28', 'home sick', 1),
(11, 8, '2020-06-28', '2020-06-28', 'Doctors Appointment', 1);

-- --------------------------------------------------------

--
-- Table structure for table `tblusers`
--

CREATE TABLE `tblusers` (
  `usrId` int(11) NOT NULL,
  `employeeId` varchar(20) NOT NULL,
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `access` varchar(15) NOT NULL,
  `isAdmin` tinyint(4) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `tblusers`
--

INSERT INTO `tblusers` (`usrId`, `employeeId`, `username`, `password`, `access`, `isAdmin`) VALUES
(2, '', 'user', 'password', 'user', 0),
(3, '', 'admin', 'password@admin', 'admin', 0),
(4, '', 'pax', 'pax', 'admin', 1),
(1001, '25', 'ellis', 'pax', 'admin', 1),
(1002, '3', 'floyd1991', 'gweru', 'user', 0),
(1003, '7', 'qwerty1998', 'qwe', 'user', 0),
(1004, '8', 'New1999', '1234', 'user', 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tblbills`
--
ALTER TABLE `tblbills`
  ADD PRIMARY KEY (`billID`);

--
-- Indexes for table `tbldepts`
--
ALTER TABLE `tbldepts`
  ADD PRIMARY KEY (`deptID`);

--
-- Indexes for table `tblemployees`
--
ALTER TABLE `tblemployees`
  ADD PRIMARY KEY (`employeeId`);

--
-- Indexes for table `tblleave`
--
ALTER TABLE `tblleave`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `tblusers`
--
ALTER TABLE `tblusers`
  ADD PRIMARY KEY (`usrId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `tblbills`
--
ALTER TABLE `tblbills`
  MODIFY `billID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `tblemployees`
--
ALTER TABLE `tblemployees`
  MODIFY `employeeId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `tblleave`
--
ALTER TABLE `tblleave`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `tblusers`
--
ALTER TABLE `tblusers`
  MODIFY `usrId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1005;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
