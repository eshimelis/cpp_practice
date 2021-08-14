class Solution(object):
    def licenseKeyformatting(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """

        # remove all dashes and convert to upper
        s = s.replace('-', '')
        s = s.upper()

        # reverse for easier parsing
        result = ""

        if len(s) > 0:
            while len(s) >= k:
                result = s[-k:] + '-' + result
                s = s[0:-k]

            # cleanup
            result = result[0:-1]

            if len(s) > 0:
                result = s + '-' + result

            if result[-1] == '-':
                result = result[0:-1]

            return result
        else:
            return s

