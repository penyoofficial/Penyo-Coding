<script lang="ts">
import { ElRow, ElDivider, ElButton, ElText, ElScrollbar, ElTimeline, ElTimelineItem } from 'element-plus'
export default {
  name: "IDCodeGenerator",
  data(): {
    condition: {
      area: string
      birthday: Date | null
      sex: string
    },
    areas: unknown,
    sexs: unknown,
    ops: {
      value: string
      timestamp: string
    }[]
  } {
    return {
      condition: {
        area: "",
        birthday: null,
        sex: ""
      },
      areas: [
        {
          value: '110000',
          label: '北京市',
          children: [
            {
              value: '110100',
              label: '北京市',
              children: [
                { value: '110101', label: '东城区' },
                { value: '110102', label: '西城区' },
                { value: '110105', label: '朝阳区' },
                // 更多地区...
              ],
            },
          ],
        },
        {
          value: '120000',
          label: '天津市',
          children: [
            {
              value: '120100',
              label: '天津市',
              children: [
                { value: '120101', label: '和平区' },
                { value: '120102', label: '河东区' },
                { value: '120103', label: '河西区' },
                // 更多地区...
              ],
            },
          ],
        },
        {
          value: '130000',
          label: '河北省',
          children: [
            {
              value: '130100',
              label: '石家庄市',
              children: [
                { value: '130102', label: '长安区' },
                { value: '130104', label: '桥西区' },
                { value: '130105', label: '新华区' },
                // 更多地区...
              ],
            },
            {
              value: '130200',
              label: '唐山市',
              children: [
                { value: '130202', label: '路南区' },
                { value: '130203', label: '路北区' },
                { value: '130204', label: '古冶区' },
                // 更多地区...
              ],
            },
            // 更多城市...
          ],
        },
        // 更多省份...
      ],
      sexs: [{ value: "1", label: "男" }, { value: "2", label: "女" }],
      ops: []
    }
  },
  components: {
    ElRow,
    ElDivider,
    ElButton,
    ElText,
    ElScrollbar,
    ElTimeline,
    ElTimelineItem
  },
  methods: {
    newOP() {
      this.ops.unshift({
        value: (() => {
          let area = this.condition.area[2] || "110101"
          let birthday = ((date: Date | null) => {
            if (!date)
              date = new Date()
            const year = date.getFullYear().toString()
            const month = (date.getMonth() + 1).toString().padStart(2, '0')
            const day = date.getDate().toString().padStart(2, '0')
            return year + month + day
          })(this.condition.birthday)
          const getOdd = (upper: number): number => {
            const maybeOdd = Math.round((Math.random() * 100)) % upper
            if (maybeOdd % 2)
              return maybeOdd
            return getOdd(upper)
          }
          let sex = ((this.condition.sex ? getOdd(1000) : getOdd(1000) - 1) + "").padStart(3, '0')
          const factors = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
          const code17 = area + birthday + sex
          let sum = 0
          for (let i = 0; i < 17; i++)
            sum += factors[i] * parseInt(code17[i])
          if (sum % 11 === 2)
            return code17 + "X"
          else if (sum % 11 < 1)
            return code17 + (1 - sum % 11)
          else
            return code17 + (12 - sum % 11)
        })(),
        timestamp: (() => {
          const date = new Date()
          const hours = date.getHours().toString().padStart(2, '0')
          const minutes = date.getMinutes().toString().padStart(2, '0')
          const seconds = date.getSeconds().toString().padStart(2, '0')
          return `${hours}:${minutes}:${seconds}`
        })()
      })
    },
    re(fn: Function, times: number) {
      while (times--)
        fn()
    }
  }
}
</script>

<template>
  <el-row id="conditions">
    <el-cascader class="c" v-model="condition.area" :options="areas" :show-all-levels="false" placeholder="出生地" />
    <el-date-picker class="c" v-model="condition.birthday" type="date" placeholder="生日" />
    <el-cascader class="c" v-model="condition.sex" :options="sexs" placeholder="性别" />
  </el-row>
  <el-row>
    <el-button type="primary" @click="newOP">生成一个</el-button>
    <el-button type="primary" @click="re(newOP, 10)">生成十个</el-button>
    <el-text type="primary" style="margin: 0 3em 0 1em;">总数：{{ ops.length }}</el-text>
    <el-button type="warning" @click="ops = []">清空</el-button>
  </el-row>
  <el-divider />
  <el-scrollbar height="320px">
    <el-timeline style="width: 50%; transform: translateX(0.5em);">
      <el-timeline-item v-for="op in ops" :timestamp="op.timestamp" :color="op === ops[0] ? '#0bbd87' : ''">
        {{ op.value }}
      </el-timeline-item>
    </el-timeline>
  </el-scrollbar>
</template>

<style >
#conditions {
  margin-bottom: 1em;
}

#conditions .c {
  margin-right: 1em;
}

#conditions .c:nth-child(2),
#conditions .c:nth-child(3) {
  width: 10em;
}
</style>